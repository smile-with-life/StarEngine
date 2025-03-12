#pragma once
#include <concepts>

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
    
    //可比较类型
    template<class Type>
    concept ComparableType = requires(const Type & left, const Type & right)
    {
        { left == right } -> std::convertible_to<bool>;
        { left != right } -> std::convertible_to<bool>;
        { left == right } -> std::convertible_to<bool>;
        { left != right } -> std::convertible_to<bool>;
        { left <  right } -> std::convertible_to<bool>;
        { left <= right } -> std::convertible_to<bool>;
        { left >  right } -> std::convertible_to<bool>;
        { left >= right } -> std::convertible_to<bool>;
    };

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
        { left <  right } -> std::convertible_to<bool>;
        { left <= right } -> std::convertible_to<bool>;
        { left >  right } -> std::convertible_to<bool>;
        { left >= right } -> std::convertible_to<bool>;
    };

}// namespace Concept