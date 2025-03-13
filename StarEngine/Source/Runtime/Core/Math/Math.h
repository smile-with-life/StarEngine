#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Concept/Concept.h"
#include <cmath>

namespace Star::Math
{
    inline constexpr float pi = (3.1415926535897932f); // 数学常数π
    inline constexpr float e = (2.71828182845904523536f);// 数学常数e
    inline constexpr float phi = (1.6180339887498948482045868343656381f);// 黄金分割比
    inline constexpr float SmallNum = (1.e-8f);// 较小的值
    inline constexpr float BigNum = (3.4e+38f);// 较大的值
    inline constexpr float epsilon = (1.e-4f);// 误差值

    // 绝对值
    template<class Type>
    constexpr Type Abs(const Type value)
    {
        return (value < (Type)0) ? -value : value;
    }

    // 最大值
    template<class Type>
    constexpr Type Max(const Type value1, const Type value2)
    {
        return (value1 > value2) ? value1 : value2;
    }

    // 绝对值最大值
    template<class Type>
    constexpr Type AbsMax(const Type value1, const Type value2)
    {
        return (Abs(value1) > Abs(value2)) ? value1 : value2;
    }

    // 最小值
    template<class Type>
    constexpr Type Min(const Type value1, const Type value2)
    {
        return (value1 < value2) ? value1 : value2;
    }

    // 绝对值最小值
    template<class Type>
    constexpr Type AbsMin(const Type value1, const Type value2)
    {
        return (Abs(value1) < Abs(value2)) ? value1 : value2;
    }

    // 计算平方根
    template<Concept::FloatPointType Type>
    constexpr Type Sqrt(const Type value)
    {
        return std::sqrt(value);
    }

    // 计算倒置平方根
    template<Concept::FloatPointType Type>
    constexpr Type InvSqrt(const Type value)
    {
        return 1 / std::sqrt(value);
    }

    // 计算立方根
    template<Concept::FloatPointType Type>
    constexpr Type Cbrt(const Type value)
    {
        return std::sqrt(value);
    }

    // 计算倒置立方根
    template<Concept::FloatPointType Type>
    constexpr Type InvCbrt(const Type value)
    {
        return 0;
    }

    // 
    template<class Type>
    constexpr Type Pow(const Type base, const Type exp)
    {
        return 0;
    }

    template<class Type>
    constexpr Type log10(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type log2(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type ln(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type sin(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type cos(const Type value)
    {
        return 0;
    }
    
    template<class Type>
    constexpr Type tan(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type arcsin(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type arccos(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type arctan(const Type value)
    {
        return 0;
    }
    
    template<class Type>
    constexpr Type sinh(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type cosh(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type tanh(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type arsinh(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type arcosh(const Type value)
    {
        return 0;
    }

    template<class Type>
    constexpr Type artanh(const Type value)
    {
        return 0;
    }
}