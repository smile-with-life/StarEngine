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