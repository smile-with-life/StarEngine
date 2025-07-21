#pragma once

#include <algorithm>

#include "Core/Core.h"
#include "Core/Concept/Concept.h"

namespace Star
{
// 两个参数中的最大值
template<Concept::SortComparableType Type>
constexpr const Type& Max(const Type& a, const Type& b)
{
    return (a > b) ? a : b;
}

// 列表中的最大值
template<Concept::SortComparableType Type>
constexpr const Type Max(std::initializer_list<Type> ilist)
{
    return std::max(ilist);
}

// 两个参数中的最小值
template<Concept::SortComparableType Type>
constexpr Type& Min(const Type& a, const Type& b)
{
    return (a < b) ? a : b;
}

// 列表中的最小值
template<Concept::SortComparableType Type>
constexpr Type Min(std::initializer_list<Type> ilist)
{
    return std::min(ilist);
}
}// namespace Star