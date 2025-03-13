#pragma once
#include "Runtime/Core/Core.h"
#include <algorithm>
namespace Star
{
// 最大值
template<class Type>
constexpr Type& Max(const Type& a, const Type& b)
{
    return (a > b) ? a : b;
}

// 最大值
template<class Type>
constexpr Type Max(std::initializer_list<Type> ilist)
{
    return std::max(ilist);
}

// 最小值
template<class Type>
constexpr Type& Min(const Type& a, const Type& b)
{
    return (a < b) ? a : b;
}

// 最小值
template<class Type>
constexpr Type Min(std::initializer_list<Type> ilist)
{
    return std::min(ilist);
}
}// namespace Star