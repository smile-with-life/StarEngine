Chromium Embedded Framework (CEF) Minimal Binary Distribution for Windows
-------------------------------------------------------------------------------

Date:             July 18, 2025

CEF Version:      138.0.26+g84f2d27+chromium-138.0.7204.158
CEF URL:          https://bitbucket.org/chromiumembedded/cef.git
                  @84f2d2762cdfe6bead1b531c9f86c0e23bf7fd1f

Chromium Version: 138.0.7204.158
Chromium URL:     https://chromium.googlesource.com/chromium/src.git
                  @903c1a4e1274a274ac03d20a24ab16634d064418

This distribution contains the minimal components necessary to build and
distribute an application using CEF on the Windows platform. Please see
the LICENSING section of this document for licensing terms and conditions.


CONTENTS
--------

bazel       Contains Bazel configuration files shared by all targets.

cmake       Contains CMake configuration files shared by all targets.

include     Contains all required CEF header files.

libcef_dll  Contains the source code for the libcef_dll_wrapper static library
            that all applications using the CEF C++ API must link against.

Release     Contains libcef.dll, libcef.lib and other components required to
            build and run the release version of CEF-based applications. By
            default these files should be placed in the same directory as the
            executable.

Resources   Contains resources required by libcef.dll. By default these files
            should be placed in the same directory as libcef.dll.


USAGE
-----

Building using CMake:
  CMake can be used to generate project files in many different formats. See
  usage instructions at the top of the CMakeLists.txt file.

Building using Bazel:
  Bazel can be used to build CEF-based applications. CEF support for Bazel is
  considered experimental. For current development status see
  https://github.com/chromiumembedded/cef/issues/3757.

Please visit the CEF Website for additional usage information.

https://bitbucket.org/chromiumembedded/cef/


REDISTRIBUTION
--------------

This binary distribution contains the below components.

Required components:

The following components are required. CEF will not function without them.

* CEF core library.
  * libcef.dll

* Crash reporting library.
  * chrome_elf.dll

* Unicode support data.
  * icudtl.dat

* V8 snapshot data.
  * v8_context_snapshot.bin

Optional components:

The following components are optional. If they are missing CEF will continue to
run but any related functionality may become broken or disabled.

* Localized resources.
  Locale file loading can be disabled completely using
  CefSettings.pack_loading_disabled. The locales directory path can be
  customized using CefSettings.locales_dir_path. 
 
  * locales/
    Directory containing localized resources used by CEF, Chromium and Blink. A
    .pak file is loaded from this directory based on the CefSettings.locale
    value. Only configured locales need to be distributed. If no locale is
    configured the default locale of "en-US" will be used. Without these files
    arbitrary Web components may display incorrectly.

* Other resources.
  Pack file loading can be disabled completely using
  CefSettings.pack_loading_disabled. The resources directory path can be
  customized using CefSettings.resources_dir_path.

  * chrome_100_percent.pak
  * chrome_200_percent.pak
  * resources.pak
    These files contain non-localized resources used by CEF, Chromium and Blink.
    Without these files arbitrary Web components may display incorrectly.

* Direct3D support.
  * d3dcompiler_47.dll
  Support for GPU accelerated rendering of HTML5 content like 2D canvas, 3D CSS
  and WebGL. Without this file the aforementioned capabilities may fail when GPU
  acceleration is enabled (default in most cases). Use of this bundled version
  is recommended instead of relying on the possibly old and untested system
  installed version.

* DirectX compiler support (x64 only).
  * dxil.dll
  * dxcompiler.dll
  Support for DirectX rendering of WebGPU. Without these files the
  aforementioned capabilities may fail.

* ANGLE support.
  * libEGL.dll
  * libGLESv2.dll
  Support for rendering of HTML5 content like 2D canvas, 3D CSS and WebGL.
  Without these files the aforementioned capabilities may fail.

* SwANGLE support.
  * vk_swiftshader.dll
  * vk_swiftshader_icd.json
  * vulkan-1.dll
  Support for software rendering of HTML5 content like 2D canvas, 3D CSS and
  WebGL using SwiftShader's Vulkan library as ANGLE's Vulkan backend. Without
  these files the aforementioned capabilities may fail when GPU acceleration is
  disabled or unavailable.


LICENSING
---------

The CEF project is BSD licensed. Please read the LICENSE.txt file included with
this binary distribution for licensing terms and conditions. Other software
included in this distribution is provided under other licenses. Please see the
CREDITS.html file or visit "about:credits" in a CEF-based application for
complete Chromium and third-party licensing information.
