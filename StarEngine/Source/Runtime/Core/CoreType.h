#pragma once

#include <cstdint>
#include <concepts>

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

using u8char = char8;
using u16char = char16;
using u32char = char32;

using ptrdiff = std::ptrdiff_t;

using Handle = uint32;

namespace Concept
{
// 算数类型
template<class Type>
concept ArithmeticType = std::is_arithmetic_v<Type>;

// 整数类型
template<class Type>
concept IntegralType = std::integral<Type>;

// 浮点类型
template<class Type>
concept FloatPointType = std::floating_point<Type>;

// 随机访问迭代器类型
//template<class Type>
//using RandomIteratorType = std::random_access_iterator<Type>;

// 支持相等的可比较类型
template<class Type>
concept EqualComparableType = requires(const Type & left, const Type & right)
{
    { left == right } -> std::convertible_to<bool>;
    { left != right } -> std::convertible_to<bool>;
};

// 支持排序的可比较类型
template<class Type>
concept SortComparableType = requires(const Type & left, const Type & right)
{
    { left == right } -> std::convertible_to<bool>;
    { left != right } -> std::convertible_to<bool>;
    { left < right } -> std::convertible_to<bool>;
    { left <= right } -> std::convertible_to<bool>;
    { left > right } -> std::convertible_to<bool>;
    { left >= right } -> std::convertible_to<bool>;
};

}// namespace Concept