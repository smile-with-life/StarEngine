#pragma once

#include "Runtime/Core/Core.h"
#include <cmath>

namespace Star::Math
{
    inline constexpr float pi = (3.1415926535897932f); // 数学常数π
    inline constexpr float e = (2.71828182845904523536f);// 数学常数e
    inline constexpr float goldRatio = (1.6180339887498948482045868343656381f);// 黄金分割比

    inline constexpr float SmallNum = (1.e-8f);
    inline constexpr float BigNum = (3.4e+38f);
    inline constexpr float epsilon = (1.e-4f);


    template<class Type>
    static constexpr Type Abs(const Type value)
    {
        return (value < (Type)0) ? -value : value;
    }

    template<class Type>
    static constexpr Type Max(const Type value1, const Type value2)
    {
        return (value1 > value2) ? value1 : value2;
    }

    template<class Type>
    static constexpr Type AbsMax(const Type value1, const Type value2)
    {
        return (Abs(value1) > Abs(value2)) ? value1 : value2;
    }

    template<class Type>
    static constexpr Type Min(const Type value1, const Type value2)
    {
        return (value1 < value2) ? value1 : value2;
    }

    template<class Type>
    static constexpr Type AbsMin(const Type value1, const Type value2)
    {
        return (Abs(value1) < Abs(value2)) ? value1 : value2;
    }

    template<Concept::FloatPointType Type>
    static constexpr Type Sqrt(const Type value)
    {
        return std::sqrt(value);
    }

    template<Concept::FloatPointType Type>
    static constexpr Type InvSqrt(const Type value)
    {
        return 1 / std::sqrt(value);
    }
    
    
}