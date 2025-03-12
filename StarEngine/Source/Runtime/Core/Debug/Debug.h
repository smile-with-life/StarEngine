#pragma once
#include"Runtime/Core/Core.h"

// 调试支持
#if defined(STAR_TEST) || defined(STAR_DEBUG)
    #if defined(STAR_PLATFORM_WINDOWS)
        #define DebugBreak() __debugbreak()
    #else
        #error StarEngine only support Windows!
    #endif
#else
    #define DebugBreak()
#endif

// 断言
#ifdef STAR_TEST
    #include <assert.h>
    #define Assert(expression) assert(expression)
#else
    #define Assert(expression) ((void)0)
#endif

namespace Star
{
class DebugOutput
{

};

inline DebugOutput console;
}// namespace Star
