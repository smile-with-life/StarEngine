import {ChannelLog} from "channel-log.js";
import {View} from "view.js";
import {FilesView} from "files-view.js";
import {DOMView, ElementDetailsView} from "dom-view.js";
import {MemoryView} from "memory-view.js";
import {DebuggerView} from "debugger.js";

export class ChannelView extends Element {
  channel = null;
  stack = null; // dom element stack

  constructor(props) {
    super();
    this.channel = props.channel;
    this.viewstate = this.channel.viewstate;
    this.channel.view = this;
  }

  render(props) {
    let viewContent;
    let headerViewContent;
    let detailsViewContent;

    switch (this.currentView) {
      default:
      case "DOMView":
        viewContent = <DOMView channel={this.channel} stack={this.stack} />;
        headerViewContent = DOMView.header(this.channel);
        this.stack = null;        
        break;
      case "FilesView":
        {
          const filetoshow = this.filetoshow; this.filetoshow = null;
          viewContent = <FilesView channel={this.channel} filetoshow={filetoshow}/>;
          headerViewContent = FilesView.header(this.channel);
        }
        break;
      case "MemoryView":
        viewContent = <MemoryView channel={this.channel} />;
        headerViewContent = MemoryView.header(this.channel);
        break;
    }

    switch (this.currentDetailsView) {
      default:
      case "ElementDetailsView": detailsViewContent = <ElementDetailsView channel={this.channel} />; break;
      case "FilesDetailsView": detailsViewContent = <DebuggerView channel={this.channel} />; break;
      case "MemoryDetailsView": detailsViewContent = <div/>; break;
    }

    // console.log("ChannelView render",this.channel.theirFiles.length);
    const nFiles = Object.values(this.channel.theirFiles).length;

    return <main>
      <frameset cols="*,300px">
        <section .tabs #channel-view>
          <header>
            <label#FilesView detailsId="FilesDetailsView" current={ this.currentView == "FilesView"}>Files({nFiles})</label>
            <label#MemoryView detailsId="MemoryDetailsView" current={ this.currentView == "MemoryView"}>Memory</label>
            <label#DOMView detailsId="ElementDetailsView" current={ this.currentView == "DOMView"}>DOM</label>
            {headerViewContent}
          </header>
          <frameset rows="2*,*" >
            <section #main-view>
              { viewContent }
            </section>
            <splitter/>
            <ChannelLog channel={this.channel} />
          </frameset>
        </section>
        <splitter/>
        <section #details-view>
          { detailsViewContent }
        </section>
      </frameset>
    </main>;
  }

  get currentView() {
    return this.viewstate.view || "DOMView";
  }

  set currentView(v) {
    this.viewstate.view = v;
  }

  get currentDetailsView() {
    return this.viewstate.detailsView || "ElementDetailsView";
  }

  set currentDetailsView(v) {
    this.viewstate.detailsView = v;
  }

  // componentUpdate(newState) {
  //  super.componentUpdate(newState);
  // }

  ["on click at #channel-view > header > label:not(:current)"](evt, label) {
    this.componentUpdate({
      currentView: label.id,
      currentDetailsView: label.getAttribute("detailsId")
    });
    return true;
  }

  ["on domstackchange"](evt) {
    this.componentUpdate();
    return false;
  }


  ["on file-show"](evt) {
    const newState = {
      currentView: "FilesView",
      filetoshow: evt.detail,
    };
    if (evt.detail.withDetails)
      newState.currentDetailsView = "FilesDetailsView";

    this.componentUpdate(newState);

    return false;
  }

  onBreakpointHit(filename, lineno, callstack) {
    const newState = {
      currentView: "FilesView",
      currentDetailsView: "FilesDetailsView",
      filetoshow: {url: filename, lineno: lineno},
    };
    this.componentUpdate(newState);
  }

  requestUpdate() {
    this.timer(1000, this.componentUpdate);
  }

  async ["on navigate-to"](evt) {
    const elementUid = evt.data;
    const stack = await this.channel.request("stackOf", elementUid);
    this.componentUpdate({currentView: "DOMView", stack});
    return true;
  }

}
