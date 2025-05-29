#pragma once

#include <cstdint>
#include <cstddef>

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
    #undef GetObject
#endif

#ifdef STAR_PLATFORM_WINDOWS
    inline SE_API HINSTANCE GWindowsInstance;
#endif

using uchar = unsigned char;
using ushort = unsigned short;
using uint = unsigned int;
using ulong = unsigned long;

using int8 = std::int8_t;
using int16 = std::int16_t;
using int32 = std::int32_t;
using int64 = std::int64_t;

using uint8 = std::uint8_t;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;

using char8 = char8_t;
using char16 = char16_t;
using char32 = char32_t;

using wchar = wchar_t;

using ptrdiff = std::ptrdiff_t;

using Handle = uint32;
