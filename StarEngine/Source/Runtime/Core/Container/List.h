#pragma once
#include <list>
#include "Runtime/Core/Core.h"
namespace Star
{
template<class Type>
class List
{
public:
    using iterator = std::list<Type>::iterator;
    using const_iterator = std::list<Type>::const_iterator;
    using reverse_iterator = std::list<Type>::reverse_iterator;
    using const_reverse_iterator = std::list<Type>::const_reverse_iterator;
public:
    List() = default;

    ~List() = default;

    List(const List& other)
        : m_data(other.m_data)
    {

    }

    List& operator=(const List& other)
    {
        if (this == &other) [[unlikely]]
        {
            return *this;
        }

        m_data = other.m_data;
    }

    List(List&& other) noexcept
        : m_data(std::move(other.m_data))
    {

    }

    List& operator=(List&& other) noexcept
    {
        if (this == &other) [[unlikely]]
        {
            return *this;
        }

        m_data = std::move(other.m_data);
    }

    List(int64 count)
        : m_data(count)
    {

    }

    List(int64 count, const Type& value)
        : m_data(count, value)
    {

    }

    template< class InputIt >
    List(InputIt first, InputIt last)
        : m_data(first, last)
    {

    }

    constexpr List(std::initializer_list<Type> ilist)
        : m_data(ilist)
    {

    }

    constexpr List& operator=(std::initializer_list<Type> ilist)
    {
        m_data = ilist;
    }
public:
    Type& Front()
    {
        return m_data.front();
    }
    
    const Type& Front() const
    {
        return m_data.front();
    }

    Type& Back()
    {
        return m_data.back();
    }

    const Type& Back() const
    {
        return m_data.back();
    }
public:
    bool IsEmpty() const
    {
        return m_data.empty();
    }

    int64 Size() const
    {
        return m_data.size();
    }

    int64 Max() const
    {
        return m_data.max_size();
    }

    void Clear()
    {
        m_data.clear();
    }

    void Resize(int64 size)
    {
        m_data.resize(size);
    }
    

    List& Append(const Type& value)
    {
        m_data.insert(m_data.end(), value);
        return *this;
    }

    List& operator+=(const Type& value)
    {
        return Append(value);
    }

    List& Append(Type&& value)
    {
        m_data.insert(m_data.end(), std::forward<Type>(value));
        return *this;
    }

    List& operator+=(Type&& value)
    {
        return Append(std::move(value));
    }
    
    List& Append(const List& other)
    {
        m_data.insert(m_data.end(), other.m_data.begin(), other.m_data.end());
        return *this;
    }

    List& operator+=(const List& other)
    {
        return Append(other);
    }

    List& Prepend(const Type& value)
    {
        m_data.insert(m_data.begin(), value);
        return *this;
    }

    List& Prepend(Type&& value)
    {
        m_data.insert(m_data.begin(), std::forward<Type>(value));
        return *this;
    }

    List& Prepend(const List& other)
    {
        m_data.insert(m_data.begin(), other.m_data.begin(), other.m_data.end());
        return *this;
    }

    iterator Insert(const_iterator iter, const Type& value)
    {
        return m_data.insert(iter, value);
    }

    iterator Insert(const_iterator iter, Type&& value)
    {
        return m_data.insert(iter, std::forward<Type>(value));
    }

    iterator Insert(const_iterator iter, int64 count, const Type& value)
    {
        return m_data.insert(iter, count, value);
    }

    template<class InputIt>
    iterator Insert(const_iterator iter, InputIt first, InputIt last)
    {
        return m_data.insert(iter, first, last);
    }

    iterator Insert(const_iterator iter, std::initializer_list<Type> ilist)
    {
        return m_data.insert(iter, ilist);
    }

    template<class... Args>
    iterator Emplace(const_iterator iter, Args&&... args)
    {
        return m_data.emplace(iter, std::forward<Args>(args)...);
    }

    iterator Erase(const_iterator iter)
    {
        return m_data.erase(iter);
    }

    iterator Erase(const_iterator firstIter, const_iterator lastIter)
    {
        return m_data.erase(firstIter, lastIter);
    }

    void PushBack(const Type& value)
    {
        m_data.push_back(value);
    }

    void PushBack(Type&& value)
    {
        m_data.push_back(std::forward<Type>(value));
    }

    template<class... Args>
    Type& EmplaceBack(Args&&... args)
    {
        return m_data.emplace_back(std::forward<Args>(args)...);
    }

    void PopBack()
    {
        m_data.pop_back();
    }

    void PushFront(const Type& value)
    {
        m_data.push_front(value);
    }

    void PushFront(Type&& value)
    {
        m_data.push_front(std::forward<Type>(value));
    }

    template<class... Args>
    Type& EmplaceFront(Args&&... args)
    {
        return m_data.emplace_front(std::forward<Args>(args)...);
    }

    void PopFront()
    {
        m_data.pop_front();
    }
public:
    void Merge(List& other)
    {
        m_data.merge(other.m_data);
    }

    void Merge(List&& other)
    {
        m_data.merge(std::move(other.m_data));
    }

    template<class Compare>
    void Merge(List& other, Compare comp)
    {
        m_data.merge(other.m_data, comp);
    }

    template< class Compare >
    void Merge(List&& other, Compare comp)
    {
        m_data.merge(std::move(other.m_data), comp);
    }

    void Splice(const_iterator pos, List& other)
    {
        m_data.splice(pos, other.m_data);
    }

    void Splice(const_iterator pos, List&& other)
    {
        m_data.splice(pos, std::move(other.m_data));
    }

    void Splice(const_iterator pos, List& other, const_iterator iter)
    {
        m_data.splice(pos, other.m_data, iter);
    }

    void Splice(const_iterator pos, List&& other, const_iterator iter)
    {
        m_data.splice(pos, std::move(other.m_data), iter);
    }

    void Splice(const_iterator pos, List& other, const_iterator first, const_iterator last)
    {
        m_data.splice(pos, other.m_data, first, last);
    }

    void Splice(const_iterator pos, List&& other, const_iterator first, const_iterator last)
    {
        m_data.splice(pos, std::move(other.m_data), first, last);
    }

    int64 Remove(const Type& value)
    {
        return m_data.remove(value);
    }

    template<class UnaryPredicate>
    int64 RemoveIf(UnaryPredicate p)
    {
        return m_data.remove_if(p);
    }

    void Reverse() noexcept
    {
        m_data.reverse();
    }

    int64 Unique()
    {
        return m_data.unique();
    }

    template<class BinaryPredicate>
    int64 Unique(BinaryPredicate p)
    {
        return m_data.unique(p);
    }

    void Sort()
    {
        m_data.sort();
    }

    template<class Compare >
    void Sort(Compare comp)
    {
        m_data.sort(comp);
    }
public:
    template<Concept::EqualComparableType Type>
    bool operator==(const List<Type>& other)
    {
        return m_data == other.m_data;
    }

    template<Concept::EqualComparableType Type>
    bool operator!=(const List<Type>& other)
    {
        return m_data != other.m_data;
    }

    template<Concept::SortComparableType Type>
    bool operator>(const List<Type>& other)
    {
        return m_data > other.m_data;
    }

    template<Concept::SortComparableType Type>
    bool operator>=(const List<Type>& other)
    {
        return m_data >= other.m_data;
    }

    template<Concept::SortComparableType Type>
    bool operator<(const List<Type>& other)
    {
        return m_data < other.m_data;
    }

    template<Concept::SortComparableType Type>
    bool operator<=(const List<Type>& other)
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
private:
    std::list<Type> m_data;
};
}// namespace Star