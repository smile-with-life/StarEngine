
#include "sciter-x-window.hpp"
#include "sciter-x-graphics.hpp"
#include "sciter-x-types.h"

#include "../sciter-sqlite/sciter-sqlite.h"

class uSciter: public sciter::window {
public:
  uSciter() : window( SW_MAIN /*| SW_ENABLE_DEBUG - frame sets it manually*/) {}

  //int foo(int p) { return p + 42; }
  //int bar(int p1, int p2) { return p1 + p2; }
  //std::vector<int> vector() { return {1,2,3}; }

  int get_windowHandle() {
    return (int)(intptr_t)get_hwnd();
  }

  SOM_PASSPORT_BEGIN(uSciter)
    //SOM_FUNCS(
      //SOM_FUNC(foo),
      //SOM_FUNC(bar),
      //SOM_FUNC(vector),
    //)
    SOM_PROPS(SOM_RO_VIRTUAL_PROP(windowHandle,get_windowHandle))
  SOM_PASSPORT_END

  /* sample of handling DOM events, click on <button#foo> here:
  virtual bool handle_event(HELEMENT, BEHAVIOR_EVENT_PARAMS& params) {
    sciter::dom::element target = params.heTarget;
    switch (params.cmd) {
      case BUTTON_CLICK:
        if (target.test("button#foo")) {
          target.set_html((const unsigned char*)"foo", 3);
          return true;
        }
    }
    return false;
  }*/

#if 1
  // behavioral "named call" handler demo:
  // test in script:
  //
  //  Window.this.xcall("debug",12,24);
  //

  BEGIN_FUNCTION_MAP
    FUNCTION_V("debug", debug);
  END_FUNCTION_MAP

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
#endif



};

#include "resources.cpp"

int uimain(std::function<int()> run ) {

//#if defined(LINUX)
//SciterSetOption(NULL, SCITER_SET_GFX_LAYER, GFX_LAYER_SKIA_METAL);
//#endif


  // enable features to be used from script
  SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES,
                          ALLOW_FILE_IO |
                          ALLOW_SOCKET_IO |
                          ALLOW_EVAL |
                          ALLOW_SYSINFO | 
                          ALLOW_CMODULES );

  sciter::value mediaVars = sciter::value::make_map({
    {sciter::value("brand"),sciter::value("terra")}
  });

  SciterSetMediaVars(NULL, &mediaVars);


  //SciterSetOption(NULL, SCITER_ENABLE_UIAUTOMATION, TRUE);

  SciterSetGlobalAsset(new sqlite::SQLite()); // adding SQLite as a global namespace object

#ifdef SDEBUG
  sciter::debug_output_console console; //- uncomment it if you will need console window
#endif

  sciter::archive::instance().open(aux::elements_of(resources)); // bind resources[] (defined in "resources.cpp") with the archive

  sciter::om::hasset<uSciter> pwin = new uSciter();

  // example, setting "usciter" media variable, check https://sciter.com/forums/topic/debugging-issues/
  SciterSetMediaType(pwin->get_hwnd(), WSTR("desktop,usciter"));

  bool loaded = false;

  const std::vector<sciter::string>& argv = sciter::application::argv();

  sciter::string file_to_open;

  // usciter.exe -o file-to-open.htm
  if (argv.size() > 1) {
    for(int n = 1; n < int(argv.size()) - 1; ++n )
        if( aux::chars_of(argv[n]) == const_wchars("-o") ) {
          file_to_open = argv[n+1];
          break;
        }
    if (file_to_open.length()) {
#ifdef WINDOWS
      WCHAR fullpath[2048] = {0};
      if(GetFullPathName(file_to_open.c_str(), 2048, fullpath, NULL))
        file_to_open = fullpath;
#endif
      loaded = pwin->load(file_to_open.c_str());
    }
  }

  if (!loaded)
    // note: this:://app URL is dedicated to the sciter::archive content associated with the application
#if defined(WINDOWS)
    pwin->load(WSTR("this://app/default-win.htm"));
    //pwin->load(WSTR("file://E:/sciter/work.fx/sdk/samples.gpu/hello-es-triangle.htm"));
    //pwin->load(WSTR("file://E:/sciter/work.fx/sdk/samples.webgl/threejs/3-hello-cube.htm"));
    //pwin->expand(); // script will do that
#elif defined(OSX)
    //pwin->load(WSTR("file:///Volumes/Plus/work.fx/sdk/samples.gpu/hello-es-triangle.htm"));
    //pwin->load(WSTR("file:///Volumes/Plus/work.fx/sdk/samples.webgl/basic/1-cube-lights/index.htm"));
    //pwin->expand(); // script will do that
    pwin->load(WSTR("this://app/default-osx.htm"));
#elif defined(LINUX)
    pwin->load(WSTR("this://app/default-lnx.htm"));
#else // too many of them differnt
    pwin->load(WSTR("this://app/default-else.htm"));
#endif // WINDOWS

    if(file_to_open.length())
      pwin->expand(); // script will do that

  return run();

}
