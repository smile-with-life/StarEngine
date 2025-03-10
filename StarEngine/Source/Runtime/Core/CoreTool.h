#pragma once

#include <tchar.h>
#include "iostream"


// 生成位字段
#define BIT(x) (1 << x) 

inline WCHAR* ToWideChar(const char* str)
{
    WCHAR result[256];

    int size = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    if (size > 256)
    {
        return nullptr;
    }

    if (!MultiByteToWideChar(CP_UTF8, 0, str, -1, result, size))
    {
        return nullptr;
    }

    return result;
}