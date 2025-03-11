#pragma once

#ifdef STAR_PLATFORM_WINDOWS
    #ifdef STAR_BUILD_DLL
        #define SE_API __declspec(dllexport)
    #else
        #define SE_API __declspec(dllimport)
    #endif // STAR_BUILD_DLL
#else
    #error StarEngine only support Windows!
#endif // STAR_PLATFORM_WINDOWS

#ifdef STAR_PLATFORM_WINDOWS
    #include "Windows.h"
    // 取消宏定义
    #undef min
    #undef max
#endif

#ifdef STAR_PLATFORM_WINDOWS
    inline SE_API HINSTANCE GWindowsInstance;
#endif


#ifdef STAR_TEST
    #include <assert.h>
    #define Assert(expression) assert(expression)
#else
    #define Assert(expression) ((void)0)
#endif