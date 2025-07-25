#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>

using namespace ultralight;

const char* htmlString();

///
///  Welcome to Sample 4!
///
///  In this sample we'll show how to integrate C++ code with JavaScript.
///
///  We will introduce the DOMReady event and use it to bind a C++ callback to a JavaScript
///  function on our page. Later, when that callback is triggered, we will execute some JavaScript
///  to update a hidden message on the page.
///
///  __JavaScriptCore and AppCore__
///
///  Ultralight integrates the full JavaScriptCore engine (the same JS engine in Safari on macOS
///  and iOS). The SDK includes full C API bindings to JavaScriptCore which gives you a great deal
///  of flexibility but can be a little daunting for first-time users.
/// 
///  To help simplify things, AppCore provides a simple C++ wrapper over JavaScriptCore
///  (@see JSHelpers.h). We'll be using this wrapper for the sake of convenience in this sample.
///
class MyApp : public WindowListener,
              public LoadListener {
  RefPtr<App> app_;
  RefPtr<Window> window_;
  RefPtr<Overlay> overlay_;
public:
  MyApp() {
    ///
    /// Create our main App instance.
    ///
    /// The App class is responsible for the lifetime of the application and is required to create
    /// any windows.
    ///
    app_ = App::Create();

    ///
    /// Create our Window.
    ///
    /// This command creates a native platform window and shows it immediately.
    /// 
    window_ = Window::Create(app_->main_monitor(), 300, 300, false, kWindowFlags_Titled);

    ///
    /// Set our window title.
    ///
    window_->SetTitle("Ultralight Sample 4 - JavaScript");

    ///
    /// Register our MyApp instance as a WindowListener so we can handle the Window's OnClose
    /// event below.
    ///
    window_->set_listener(this);

    ///
    /// Create an Overlay using the same dimensions as our Window.
    ///
    overlay_ = Overlay::Create(window_, window_->width(), window_->height(), 0, 0);

    ///
    /// Register our MyApp instance as a load listener so we can handle the View's OnDOMReady
    /// event below.
    ///
    overlay_->view()->set_load_listener(this);

    ///
    /// Load a string of HTML (we're using a C++11 Raw String Literal)
    ///
    overlay_->view()->LoadHTML(htmlString());
  }

  virtual ~MyApp() {}

  ///
  /// Our native JavaScript callback. This function will be called from JavaScript by calling
  /// GetMessage(). We bind the callback within the DOMReady callback defined below.
  ///
  JSValue GetMessage(const JSObject& thisObject, const JSArgs& args) {
    ///
    /// Return our message to JavaScript as a JSValue.
    ///
    return JSValue("Hello from C++!<br/>Ultralight rocks!");
  }

  ///
  /// Inherited from LoadListener, called when the page has finished parsing the document.
  ///
  /// We perform all our JavaScript initialization here.
  ///
  virtual void OnDOMReady(ultralight::View* caller,
                          uint64_t frame_id,
                          bool is_main_frame,
                          const String& url) override {
    ///
    /// Set our View's JSContext as the one to use in subsequent JSHelper calls
    ///
    RefPtr<JSContext> context = caller->LockJSContext();
    SetJSContext(context->ctx());

    ///
    /// Get the global object (this would be the "window" object in JS)
    ///
    JSObject global = JSGlobalObject();

    ///
    /// Bind MyApp::GetMessage to the JavaScript function named "GetMessage".
    ///
    /// You can get/set properties of JSObjects by using the [] operator with the following types
    /// as potential property values:
    ///  - JSValue
    ///      Represents a JavaScript value, eg String, Object, Function, etc.
    ///  - JSCallback 
    ///      Typedef of std::function<void(const JSObject&, const JSArgs&)>)
    ///  - JSCallbackWithRetval 
    ///      Typedef of std::function<JSValue(const JSObject&, const JSArgs&)>)
    ///
    /// We use the BindJSCallbackWithRetval macro to bind our C++ class member function to our
    /// JavaScript callback.
    ///
    global["GetMessage"] = BindJSCallbackWithRetval(&MyApp::GetMessage);
  }

  ///
  /// Inherited from WindowListener, called when the Window is closed.
  /// 
  /// We exit the application when the window is closed.
  ///
  virtual void OnClose(ultralight::Window* window) override {
    app_->Quit();
  }

  ///
  /// Inherited from WindowListener, called when the Window is resized.
  /// 
  /// (Not used in this sample)
  ///
  virtual void OnResize(ultralight::Window* window, uint32_t width, uint32_t height) override {}

  void Run() {
    app_->Run();
  }
};

int main() {
  MyApp app;
  app.Run();

  return 0;
}

const char* htmlString() {
  return R"(
<html>
  <head>
    <style type="text/css">
      * { -webkit-user-select: none; }
      body { 
        font-family: -apple-system, 'Segoe UI', Arial, sans-serif; 
        text-align: center;
        background: linear-gradient(#FFF, #DDD);
        padding: 2em;
      }
      body.rainbow {
        background: linear-gradient(90deg, #ff2363, #fff175, #68ff9d, 
                                           #45dce0, #6c6eff, #9e23ff, #ff3091);
        background-size: 1000% 1000%;
        animation: ScrollGradient 10s ease infinite;
      }
      @keyframes ScrollGradient {
        0%   { background-position:0% 50%; }
        50%  { background-position:100% 50%; }
        100% { background-position:0% 50%; }
      }
      #message {
        padding-top: 2em;
        color: white;
        font-weight: bold;
        font-size: 24px;
        text-shadow: 1px 1px rgba(0, 0, 0, 0.4);
      }
    </style>
    <script type="text/javascript">
    function HandleButton(evt) {
      // Call our C++ callback 'GetMessage'
      var message = GetMessage();
      
      // Display the result in our 'message' div element and apply the
      // rainbow effect to our document's body.
      document.getElementById('message').innerHTML = message;
      document.body.classList.add('rainbow');
    }
    </script>
  </head>
  <body>
    <button onclick="HandleButton(event);">Get the Secret Message!</button>
    <div id="message"></div>
  </body>
</html>
    )";
}