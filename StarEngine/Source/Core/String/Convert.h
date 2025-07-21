#pragma once
#include "Core/Core.h"
#include "unicode/ucnv.h"
#include "unicode/unistr.h"
#include "String.h"

namespace Star::Convert
{
    inline std::wstring ToWideString(const String& str)
    {
        std::wstring result;
        wchar buffer[256];

        int size = MultiByteToWideChar(CP_UTF8, 0, str.ToCString(), -1, NULL, 0);
        if (size > 256)
        {
            // @log
            return result;
        }

        if (!MultiByteToWideChar(CP_UTF8, 0, str.ToCString(), -1, buffer, size))
        {
            // @log
            return result;
        }
        result = buffer;

        return result;
    }

    
}// namespace Star