import {$, $$, on} from "@sciter";
import {serve} from "server.js";
import {ChannelDriver} from "driver.js";
import {ChannelList} from "channel-list.js";
import {ChannelView} from "channel-view.js";
import * as Settings from "settings.js";

document.ready = function() {
  serve(ChannelDriver.factory);

  Settings.init("inspector");
};

Object.defineProperty(Array.prototype, "last", {get() {
  return this[this.length - 1];
}});

Object.defineProperty(Array.prototype, "first", {get() {
  return this[0];
}});

export class App extends Element {
  componentDidMount() {
    document.on("channel-new", () => this.componentUpdate());
    document.on("channel-gone", () => this.componentUpdate());
    document.on("file-new", () => this.componentUpdate());
    document.on("host-addresses-ready", () => this.componentUpdate());
  }

  render() {
    const current = ChannelDriver.current;
    if (current) {
      return <body .channels>
        <ChannelList current={current} all={ChannelDriver.all} />
        <ChannelView key={current.key} channel={current} />
      </body>;
    }
    return <body>
      <frame src="intro.htm" />
    </body>;
  }

  ["on channel-activate"](evt) {
    const key = evt.detail;
    ChannelDriver.current = ChannelDriver.all[key];
    this.componentUpdate();
    return false;
  }
  
  ["on channel-close"](evt) {
    const key = evt.detail;
    delete ChannelDriver.all[key];
    ChannelDriver.current = Object.values(ChannelDriver.all)[0];
    this.componentUpdate();
    return false;
  }

}

// global hyperlink handler
document.on("^click", "[href]", function(evt, hlink) {
  const data = {
    url: hlink.getAttribute("href"),
    lineno: hlink.getAttribute("lineno"),
  };
  evt.preventDefault();
  evt.stopPropagation();
  hlink.dispatchEvent(new Event("file-show", {bubbles: true, detail: data}), true);
});

document.on("keyup", function(event) {
  // compare key
  if (event.code === 'Escape') {
    Window.this.close();
  }
});
