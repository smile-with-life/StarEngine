
#include "sciter-x-window.hpp"

#include <functional>
#include <thread>
#include <chrono>

// this object is used as a global namespace NativeBackend in JS
// it is set by SciterSetGlobalAsset(new NativeBackend()); 
// and is available globally - in all windows
class NativeBackend : public sciter::om::asset<NativeBackend>
{
  class NativePromise : public sciter::om::asset<NativePromise>
  {
  public:

    sciter::value resolver;
    sciter::value rejector;

    NativePromise() {}

    sciter::value then(sciter::value resolver, sciter::value rejector) {
      this->resolver = resolver;
      this->rejector = rejector;
      return sciter::value::wrap_asset(this);
    }

    void resolve(sciter::value data) {  if (resolver.is_undefined()) return; resolver.call(data); }
    void reject(sciter::value data) { if (rejector.is_undefined()) return; rejector.call(data);
    }

    SOM_PASSPORT_BEGIN(NativePromise)
      SOM_FUNCS(
        SOM_FUNC(then),
      )
      SOM_PASSPORT_END
  };

public:
  NativeBackend() {}

  // this method starts native thread and calls callbacks methods
  bool startNativeThread(sciter::value doneCb, sciter::value progressCb)
  {
    std::thread([=]() {
      // simulate long running task
      for (int n = 0; n < 100; ++n) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        progressCb.call(n);
      }
      doneCb.call(100);
      }).detach();
      return true;
  }

  // this method starts native thread and calls callbacks methods
  bool startNativeThreadWithObject(sciter::value params)
  {
    std::thread([=]() {
      sciter::value doneCb = params["done"];
      sciter::value progressCb = params["progress"];
      // simulate long running task
      for (int n = 0; n < 100; ++n) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (!progressCb.is_undefined()) progressCb.call(n);
      }
      if (!doneCb.is_undefined()) doneCb.call(100);
      }).detach();
      return true;
  }

  // this method returns thennable object and so the function is await'able in JS
  sciter::value nativeAsyncFunction(int milliseconds)
  {
    sciter::om::hasset<NativePromise> promise = new NativePromise();

    std::thread([=]() {
      std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
      promise->resolve(42);
      }).detach();

      return sciter::value::wrap_asset(promise);
  }

  bool status = false;

  bool getStatus() const { return status; }
  bool setStatus(bool nv) {
    status = nv;
    return true;
  }

  // members of NativeBackend namespace  
  SOM_PASSPORT_BEGIN(NativeBackend)
    SOM_FUNCS(
      SOM_FUNC(startNativeThread),
      SOM_FUNC(startNativeThreadWithObject),
      SOM_FUNC(nativeAsyncFunction)
    )
    SOM_PROPS(
      SOM_VIRTUAL_PROP(status, getStatus, setStatus)
    )
  SOM_PASSPORT_END
};

class NativeObject : public sciter::om::asset<NativeObject>
{
public:
  int counter; // exposed as a property directly
  NativeObject(int c = 0) : counter(c) {}
  int inc() { return ++counter; }
  int dec() { return --counter; }
  std::string toString() const { return "NativeObject"; }
  int         valueOf() const { return counter; }
  // sample of virtual property
  int ref_counter() const { return counter; }
  bool set_ref_counter(int rc) { 
    throw sciter::om::exception("attempt to set RO property");
    return true;
  }

  bool nextItem(int& n, std::string& text) {
    if (n >= 10) return false;
    text = std::string("item") + char('A' + n);
    ++n;
    return true;
  }

  SOM_PASSPORT_BEGIN(NativeObject)
    SOM_FUNCS(
      SOM_FUNC(toString),
      SOM_FUNC(valueOf),
      SOM_FUNC(inc),
      SOM_FUNC(dec),
    )
    SOM_PROPS(
      SOM_PROP(counter),
      SOM_VIRTUAL_PROP(vcounter, ref_counter, set_ref_counter)
    )
    SOM_ITEM_NEXT(nextItem)
    SOM_PASSPORT_END
};

#if 1

// "native functions as values"

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

#endif
class frame: public sciter::window {
public:
  frame() : window(SW_MAIN | SW_ENABLE_DEBUG) {}

  int counter = 0;

  // sciter::asset interface declarations.

  // These native functions are introduced to JS through assetInterface.
  // Call them in JS as
  //
  //   Window.this.assetInterface.integerSum(12,24)
  //

  std::string      stringSum(const std::string& a, const std::string& b) { return a + "+" + b; }
  //std::string      stringSum(std::string a, std::string b) { return a + "+" + b; }
  int              integerSum(int a, int b) { return a + b; }
  std::vector<int> vectorIntegerMul(std::vector<int> vec, int multiplier) {
    // getting vector as parameter
    for (auto& el : vec)
      el *= multiplier;
    return vec; // and returning vector
  }

  std::vector<sciter::byte> bytesSum(std::vector<sciter::byte> vec1, std::vector<sciter::byte> vec2) {
    std::vector<sciter::byte> out = vec1;
    std::copy(std::begin(vec2), std::end(vec2), std::back_inserter(out));
    return out;
  }


  // this method returns native object to be used in script
  sciter::value    makeNativeObject() {
    sciter::value rv = sciter::value::wrap_asset(new NativeObject());
    return rv;
  }


  // virtual property
  int get_windowHandle() {
    return (int)(intptr_t)get_hwnd();
  }

  // these function when called from script will return map of native functions
  // suitable for native-API-for-script alike cases
  sciter::value nativeFunctionsA() //api definition
  {
    sciter::value api_map;
    api_map.set_item("add", sciter::value(add));
    api_map.set_item("sub", sciter::value(sub));
    return api_map;
  }

  sciter::value nativeFunctionsB() //api definition
  {
    // same as the above but with lambdas
    std::function<bool()>     BeginDownload = [=]() -> bool { return true; };
    std::function<bool(bool)> ShellOpen = [=](bool) -> bool { return false; };
    std::function<bool(int)>  DisableRestart = [=](int) -> bool { return false; };
    sciter::value api_map;
    api_map.set_item("beginDownload", sciter::value(BeginDownload));
    api_map.set_item("shellOpen", sciter::value(ShellOpen));
    api_map.set_item("disableRestart", sciter::value(DisableRestart));
    return api_map;
  }

  sciter::value errorGeneration() {
    return sciter::value::make_error("Test of error");
  }

  // methods associatead with the window instance.
  // accessed from JS as Window.this.assetInterface. ...
  SOM_PASSPORT_BEGIN_EX(assetInterface, frame)
    SOM_FUNCS(
      SOM_FUNC(stringSum),
      SOM_FUNC(integerSum),
      SOM_FUNC(bytesSum),
      SOM_FUNC(vectorIntegerMul),
      SOM_FUNC(errorGeneration),
      SOM_FUNC(makeNativeObject),
      SOM_FUNC(nativeFunctionsA),
      SOM_FUNC(nativeFunctionsB)
    )
    SOM_PROPS(
      SOM_RO_VIRTUAL_PROP(windowHandle,get_windowHandle)
    )
  SOM_PASSPORT_END

  // behavioral "named call" handler demo:
  // test in script:
  //
  //  Window.this.xcall("debug",12,24);
  //
  // "mapped" implementation of
  //   virtual bool sciter::event_handler::on_script_call(HELEMENT he, LPCSTR name, UINT argc, const sciter::value* argv, sciter::value& retval)

  BEGIN_FUNCTION_MAP
    FUNCTION_V("debug", debug);
    FUNCTION_1("xcallTest", xcallTest);
  END_FUNCTION_MAP

  sciter::value xcallTest(sciter::value data) {
    return data.get<int>() * 2;
  }

  sciter::value debug(unsigned argc, const sciter::value* argv)
  {
#ifdef WINDOWS
    for (unsigned n = 0; n < argc; ++n)
    {
      if (n) OutputDebugStringW(L",");
      auto s = argv[n].to_string(CVT_JSON_LITERAL);
      OutputDebugStringW(s.c_str());
    }
    OutputDebugStringW(L"\n");
#endif
    return sciter::value();
  }

  // sample of handling DOM events + sample of window->call_function("scriptFunction",...):
  virtual bool handle_event(HELEMENT, BEHAVIOR_EVENT_PARAMS& params) {
    sciter::dom::element target = params.heTarget;
    switch (params.cmd) {

      case DOCUMENT_CREATED:
      {
        // adding new instance of NativeObject into namespace of each created document 
        this->set_root_document_variable("nativeObject", sciter::value::wrap_asset(new NativeObject()));
        return true;
      }

      case BUTTON_CLICK:
        if (target.test("button#test-script-func-1")) {
          // call free function, passing integer value:
          sciter::value rv = this->call_function("scriptFunc", ++counter);
          assert(rv.get<int>() == counter);
          return true;
        }
        else if (target.test("button#test-script-func-2"))
        {
          // call function by its "path", passing script object { data: counter, title: "text" } :
          sciter::value obj;
          obj.set_item("data", ++counter);
          obj.set_item("title", "hello from native side");
          this->call_function("scriptNS.testFunc", obj);
          return true;
        }
        else if (target.test("button#test-script-func-3"))
        {
          // call function by its "path"
          try {
            this->call_function("scriptNS.testErroneousFunc");
          }
          catch (sciter::script_error e) {
             std::string err = e.what();
             if (auto pdo = sciter::debug_output::instance()) {
               pdo->print(err.c_str());
             }
          }
          return true;
        }

    }
    return false;
  }
};


#include "resources.cpp"

int uimain(std::function<int()> run ) {

  // enable features to be used from script
  SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES,
                          ALLOW_FILE_IO |
                          ALLOW_SOCKET_IO |
                          ALLOW_EVAL |
                          ALLOW_SYSINFO );

  sciter::debug_output_console console; // console.log() ->  console window

  // set NativeBackend as a global native namespace:
  SciterSetGlobalAsset(new NativeBackend());

  // resources archive
  sciter::archive::instance().open(aux::elements_of(resources)); // bind resources[] (defined in "resources.cpp") with the archive

  // set initial script, note it will be run anew on each document instance,
  // *before* document will have its DOM elements.
  sciter::window::set_init_script("globalThis.initializedByInitScript = 42");

  sciter::window::set_shared_variable("initializedByCode", 0xAF);

  sciter::om::hasset<frame> pwin = new frame();

  // example, setting "desktop" media variable, check https://sciter.com/forums/topic/debugging-issues/
  SciterSetMediaType(pwin->get_hwnd(), WSTR("desktop"));

  // note: this:://app URL is dedicated to the sciter::archive content associated with the application
  pwin->load(WSTR("this://app/default.htm"));

  pwin->expand();

  BEHAVIOR_EVENT_PARAMS evt = {0};
  evt.name = WSTR("application-event");
  evt.data.set_item("somedata", 42);
  frame::broadcast_event(evt); // this will post the event to all windows in the app

  { // calling free function declared in global namespace:
    sciter::value r1 = pwin->call_function("testFunction", 40);
    assert(r1 == sciter::value(42));
  }

  { // evaluate arbitrary JS in context of loaded document
    sciter::value r2 = pwin->eval(const_chars("testFunction(40)"));
    assert(r2 == sciter::value(42));
  }

  { // get reference to the function and call it.
    // use such reference when you need to call some function more than once
    sciter::value fn = pwin->eval(const_chars("testFunction")); // get reference
    sciter::value r2 = fn.call(40);
    assert(r2 == sciter::value(42));
  }

  { // calling method of the DOM element:
    sciter::dom::element document = pwin->root();
    sciter::dom::element body = document.find_first("body");
    sciter::value r3 = body.call_method("testMethod", 41);
    assert( r3 == sciter::value(42));
  }

  { // calling method of behavior attached to the DOM element:
    sciter::dom::element document = pwin->root();
    sciter::dom::element input = document.find_first("input#test-behavior-method-call");
    // getting 'edit' behavior 
    sciter::value edit = input.to_value().get_item("edit");
    
    // getting 'edit.selectAll` method reference
    sciter::value selectAll = edit.get_item("selectAll");
    // calling it
    selectAll.call();

    // getting native 'edit.selectionStart` property value
    sciter::value sel_start = edit.get_item("selectionStart");
    assert(sel_start.is_int() && sel_start.get<int>() == 0);
    
    //sciter::value insertText = edit.get_item("insertText");
    //insertText.call(sciter::value(" foo-bar"));

  }

  {
    // custom CSS prop, starts with single '-'
    sciter::dom::element document = pwin->root();
    auto vv = document.get_style_attribute("-test-custom-prop");
    assert(vv == WSTR("42"));
    vv = document.get_style_attribute("var(test-custom-var)");
    assert(vv == WSTR("42"));
  }


  return run();

}
