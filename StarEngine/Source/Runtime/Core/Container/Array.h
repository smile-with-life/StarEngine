#pragma once
#include <vector>
#include"Runtime/Core/Core.h"
#include"Runtime/Core/Concept/Concept.h"

namespace Star
{
template<class Type>
class Array
{
public:
    using iterator = std::vector<Type>::iterator;
    using const_iterator = std::vector<Type>::const_iterator;
    using reverse_iterator = std::vector<Type>::reverse_iterator;
    using const_reverse_iterator = std::vector<Type>::const_reverse_iterator;
public:
    constexpr Array() = default;

    constexpr ~Array() = default;

    constexpr Array(const Array& other)
        : m_data(other.m_data)
    {

    }

    constexpr Array& operator=(const Array& other)
    {
        if (this == &other) [[unlikely]]
        {
            return *this;
        }

        m_data = other.m_data;
    }

    constexpr Array(Array&& other) noexcept
        : m_data(std::move(other.m_data))
    {

    }

    constexpr Array& operator=(Array&& other) noexcept
    {
        if (this == &other) [[unlikely]]
        {
            return *this;
        }

        m_data = std::move(other.m_data);
    }

    explicit constexpr Array(int64 count)
        : m_data(count)
    {}

    explicit constexpr Array(int64 count, const Type& value)
        : m_data(count, value)
    {

    }

    template<class InputIt>
    constexpr Array(InputIt first, InputIt last)
        : m_data(first, last)
    {

    }

    constexpr Array(std::initializer_list<Type> ilist)
        : m_data(ilist)
    {

    }

    constexpr Array& operator=(std::initializer_list<Type> ilist)
    {
        m_data = ilist;
    }
public:
    constexpr Type& At(int64 index)
    {
        return m_data.at(index);
    }

    constexpr const Type& At(int64 index) const
    {
        return m_data.at(index);
    }

    constexpr Type& operator[](int64 index)
    {
        return m_data[index];
    }

    constexpr const Type& operator[](int64 index) const
    {
        return m_data[index];
    }

    constexpr Type& Front()
    {
        return m_data.front();
    }

    constexpr const Type& Front() const
    {
        return m_data.front();
    }

    constexpr Type& Back()
    {
        return m_data.back();
    }

    constexpr const Type& Back() const
    {
        return m_data.back();
    }

    constexpr Type* Data()
    {
        return m_data.data();
    }

    constexpr const Type* Data() const
    {
        return m_data.data();
    }
public:
    constexpr bool IsEmpty() const
    {
        return m_data.empty();
    }

    constexpr int64 Size() const
    {
        return m_data.size();
    }

    int64 Max() const
    {
        return m_data.max_size();
    }

    constexpr int64 Capacity() const
    {
        return m_data.capacity();
    }

    constexpr void Clear()
    {
        m_data.clear();
    }

    constexpr void Reserve(int64 size)
    {
        m_data.reserve(size);
    }

    constexpr void Resize(int64 size)
    {
        m_data.resize(size);
    }

    constexpr void Shrink()
    {
        m_data.shrink_to_fit();
    }

    constexpr Array& Append(const Type& value)
    {
        PushBack(value);
        return *this;
    }

    Array& operator+=(const Type& value)
    {
        return Append(value);
    }

    constexpr Array& Append(Type&& value) noexcept
    {
        PushBack(std::move(value));
        return *this;
    }

    Array& operator+=(Type&& value) noexcept
    {
        return Append(std::move(value));
    }

    constexpr Array& Append(const Array& other)
    {
        m_data.insert(m_data.end(), other.m_data.begin(), other.m_data.end());
        return *this;
    }

    Array& operator+=(const Array& other)
    {
        return Append(other);
    }

    constexpr iterator Insert(const_iterator iter, const Type& value)
    {
        return m_data.insert(iter, value);
    }

    constexpr iterator Insert(const_iterator iter, Type&& value)
    {
        return m_data.insert(iter, std::forward<Type>(value));
    }

    constexpr iterator Insert(const_iterator iter, int64 count, const Type& value)
    {
        return m_data.insert(iter, count, value);
    }

    template<class InputIt>
    constexpr iterator Insert(const_iterator iter, InputIt first, InputIt last)
    {
        return m_data.insert(iter, first, last);
    }

    constexpr iterator Insert(const_iterator iter, std::initializer_list<Type> ilist)
    {
        return m_data.insert(iter, ilist);
    }

    template<class... Args>
    constexpr iterator Emplace(const_iterator iter, Args&&... args)
    {
        return m_data.emplace(iter, std::forward<Args>(args)...);
    }

    constexpr iterator Erase(const_iterator iter)
    {
        return m_data.erase(iter);
    }

    constexpr iterator Erase(const_iterator firstIter, const_iterator lastIter)
    {
        return m_data.erase(firstIter, lastIter);
    }

    constexpr void PushBack(const Type& value)
    {
        m_data.push_back(value);
    }

    constexpr void PushBack(Type&& value)
    {
        m_data.push_back(std::forward<Type>(value));
    }

    template<class... Args>
    constexpr Type& EmplaceBack(Args&&... args)
    {
        return m_data.emplace_back(std::forward<Args>(args)...);
    }

    constexpr void PopBack()
    {
        m_data.pop_back();
    }

    constexpr void Swap(Array& other)
    {
        m_data.swap(other.m_data);
    }
public:
    template<Concept::EqualComparableType Type>
    bool operator==(const Array<Type>& other)
    {
        return m_data == other.m_data;
    }

    template<Concept::EqualComparableType Type>
    bool operator!=(const Array<Type>& other)
    {
        return m_data != other.m_data;
    }

    template<Concept::SortComparableType Type>
    bool operator>(const Array<Type>& other)
    {
        return m_data > other.m_data;
    }

    template<Concept::SortComparableType Type>
    bool operator>=(const Array<Type>& other)
    {
        return m_data >= other.m_data;
    }

    template<Concept::SortComparableType Type>
    bool operator<(const Array<Type>& other)
    {
        return m_data < other.m_data;
    }

    template<Concept::SortComparableType Type>
    bool operator<=(const Array<Type>& other)
    {
        return m_data <= other.m_data;
    }
public:
    [[nodiscard]] constexpr iterator begin() noexcept
    {
        return m_data.begin();
    }

    [[nodiscard]] constexpr const_iterator begin() const noexcept
    {
        return m_data.begin();
    }

    [[nodiscard]] constexpr iterator end() noexcept
    {
        return m_data.end();
    }

    [[nodiscard]] constexpr const_iterator end() const noexcept
    {
        return m_data.end();
    }

    [[nodiscard]] constexpr const_iterator cbegin() const noexcept
    {
        return m_data.cbegin();
    }

    [[nodiscard]] constexpr const_iterator cend() const noexcept
    {
        return m_data.cend();
    }

    [[nodiscard]] constexpr reverse_iterator rbegin() noexcept
    {
        return m_data.rbegin();
    }

    [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept
    {
        return m_data.rbegin();
    }

    [[nodiscard]] constexpr reverse_iterator rend() noexcept
    {
        return m_data.rend();
    }

    [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept
    {
        return m_data.rend();
    }

    [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept
    {
        return m_data.crbegin();
    }

    [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept
    {
        return m_data.crend();
    }

    template<Concept::EqualComparableType Type>
    [[nodiscard]] constexpr iterator iter_find(const Type& value) noexcept
    {
        for (iterator iter = m_data.begin(); iter != m_data.end(); ++iter)
        {
            if (value == *iter)
            {
                return iter;
            }
        }
    }

    template<Concept::EqualComparableType Type>
    [[nodiscard]] constexpr const_iterator iter_find(const Type& value) const noexcept
    {
        for (const_iterator iter = m_data.begin(); iter != m_data.end(); ++iter)
        {
            if (value == *iter)
            {
                return iter;
            }
        }
    }

    template<Concept::EqualComparableType Type>
    [[nodiscard]] constexpr const_iterator iter_cfind(const Type& value) const noexcept
    {
        for (const_iterator iter = m_data.begin(); iter != m_data.end(); ++iter)
        {
            if (value == *iter)
            {
                return iter;
            }
        }
    }

    template<Concept::EqualComparableType Type>
    [[nodiscard]] constexpr iterator iter_rfind(const Type& value) noexcept
    {
        for (reverse_iterator iter = m_data.rbegin(); iter != m_data.rend(); ++iter)
        {
            if (value == *iter)
            {
                return iter.base();
            }
        }
    }

    template<Concept::EqualComparableType Type>
    [[nodiscard]] constexpr const_iterator iter_rfind(const Type& value) const noexcept
    {
        for (const_reverse_iterator iter = m_data.rbegin(); iter != m_data.rend(); ++iter)
        {
            if (value == *iter)
            {
                return iter.base();
            }
        }
    }

    template<Concept::EqualComparableType Type>
    [[nodiscard]] constexpr const_iterator iter_crfind(const Type& value) const noexcept
    {
        for (const_reverse_iterator iter = m_data.rbegin(); iter != m_data.rend(); ++iter)
        {
            if (value == *iter)
            {
                return iter.base();
            }
        }
    }
private:
    std::vector<Type> m_data;
};
template<class Type>
Array<Type> operator+(const Array<Type>& left, const Array<Type>& right)
{
    Array<Type> array(left);
    array.Resize(left.Size() + right.Size());
    array += right;
    return array;
}
}// namespace Star