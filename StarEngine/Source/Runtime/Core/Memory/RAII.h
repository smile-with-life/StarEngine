#pragma once
#include"Runtime/Core/Core.h"
#include"Runtime/Core/Concept/Concept.h"
#include<atomic>

namespace Star
{
// 独占指针
template<Concept::ClassType Type>
class ScopePtr
{
public:
    constexpr ScopePtr() = default;

    constexpr ~ScopePtr()
    {
        if(m_ptr)
        {
            delete m_ptr;
        }
    }

    constexpr ScopePtr(const ScopePtr& other) = delete;

    constexpr ScopePtr& operator=(const ScopePtr& other) = delete;

    constexpr ScopePtr(ScopePtr&& other) noexcept
        : m_ptr(other.m_ptr)
    {
        other.m_ptr = nullptr;
    }

    constexpr ScopePtr& operator=(ScopePtr&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        return *this;
    }

    constexpr explicit ScopePtr(Type* ptr) noexcept
        : m_ptr(ptr)
    {

    }
public:
    constexpr bool IsNull() const
    {
        return m_ptr == nullptr;
    }

    constexpr void Reset(Type* ptr)
    {
        if (ptr == m_ptr) [[unlikely]]
        {
            return;
        }
        delete m_ptr;
        m_ptr = ptr;
    }

    constexpr void Delete()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }

    constexpr Type* RawPtr() const
    {
        return m_ptr;
    }

    constexpr void Swap(ScopePtr& other) noexcept
    {
        std::swap(m_ptr, other.m_ptr);
    }
public:
    constexpr ScopePtr& operator=(std::nullptr_t) noexcept
    {
        Reset();
        return *this;
    }

    constexpr operator bool() const
    {
        return static_cast<bool>(m_ptr);
    }

    constexpr bool operator!() const
    {
        return !static_cast<bool>(m_ptr);
    }

    constexpr Type& operator*() const
    {
        return *m_ptr;
    }

    constexpr Type* operator->() const
    {
        return m_ptr;
    }

    constexpr friend bool operator==(const ScopePtr<Type>& left, const ScopePtr<Type>& right)
    {
        return left.m_ptr == right.m_ptr;
    }

    //template<class Type>
    constexpr friend bool operator==(const Type* left, const ScopePtr<Type>& right)
    {
        return left== right.m_ptr;
    }

    //template<class Type>
    constexpr friend bool operator==(const ScopePtr<Type>& left, const Type* right)
    {
        return left.m_ptr == right;
    }

    //template<class Type>
    constexpr friend bool operator!=(const ScopePtr<Type>& left, const ScopePtr<Type>& right)
    {
        return left.m_ptr != right.m_ptr;
    }

    //template<class Type>
    constexpr friend bool operator!=(const Type* left, const ScopePtr<Type>& right)
    {
        return left != right.m_ptr;
    }
private:
    Type* m_ptr = nullptr;
};

template<Concept::ClassType Type, class... Args>
constexpr ScopePtr<Type> MakeScope(Args&&... args)
{
    return ScopePtr<Type>(new Type(std::forward<Args>(args)...));
}

// 共享指针
template<Concept::ClassType Type>
class SharedPtr
{
public:
    template<class Type>
    struct RefCount
    {
        std::atomic<int32> count = 1;
        Type* ptr = nullptr;

        RefCount() = default;

        RefCount(Type* ptr_)
            : ptr(ptr_)
        {
        }

        void Increase()
        {
            count.fetch_add(1, std::memory_order_relaxed);
        }

        void Decrease()
        {
            count.fetch_sub(1, std::memory_order_release);
        }

        int32 Count() const
        {
            return count.load(std::memory_order_acquire);
        }
    };
public:
    SharedPtr() = default;

    ~SharedPtr()
    {
        if (m_ref)
        {
            m_ref->Decrease();
            if (m_ref->Count() == 0) 
            {
                delete m_ref->ptr;
                delete m_ref;
            }
        }
    }
    
    SharedPtr(const SharedPtr& other)
        : m_ptr(other.m_ptr), m_ref(other.m_ref)
    {     
        if (m_ref)
        {
            m_ref->Increase();
        }     
    }

    SharedPtr& operator=(const SharedPtr& other)
    {
        if (this == &other) [[unlikely]]
        {
            return *this;
        }
        if (m_ref) 
        {
            m_ref->Decrease();
            if (m_ref->Count() == 0) 
            {
                delete m_ref->ptr;
                delete m_ref;
            }
        }
        m_ptr = other.m_ptr;
        m_ref = other.m_ref;
        if (m_ref) 
        {
            m_ref->Increase();
        }
        return *this;
    }

    SharedPtr(SharedPtr&& other) noexcept
        : m_ptr(other.m_ptr), m_ref(other.m_ref)
    {
        other.m_ptr = nullptr;
        other.m_ref = nullptr;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept
    {
        if (this == &other) [[unlikely]]
        {
            return *this;
        }
        m_ptr = other.m_ptr;
        m_ref = other.m_ref;
        other.m_ptr = nullptr;
        other.m_ref = nullptr;
        return *this;
    }

    explicit SharedPtr(Type* ptr)
        : m_ptr(ptr)
    {
        if (m_ptr)
        {
            m_ref= new RefCount<Type>(ptr);
        }
    }
public:
    constexpr bool IsNull() const
    {
        return m_ptr == nullptr;
    }

    constexpr void Reset(Type* ptr)
    {
        if (m_ref)
        {
            m_ref->Decrease();
            if (m_ref->Count() == 0)
            {
                delete m_ref->ptr;
                delete m_ref;
            }
        }
        m_ptr = ptr;
        if(ptr)
        {
            m_ref = new RefCount<Type>(ptr);
        }
    }

    constexpr void Release()
    {
        if (m_ref)
        {
            m_ref->Decrease();
            if (m_ref->Count() == 0)
            {
                delete m_ref->ptr;
                delete m_ref;
            }
        }
        m_ptr = nullptr;
        m_ref = nullptr;    
    }

    constexpr Type* RawPtr() const
    {
        return m_ptr;
    }

    constexpr void Swap(SharedPtr& other) noexcept
    {
        std::swap(m_ptr, other.m_ptr);
        std::swap(m_ref, other.m_ref);
    }
public:
    constexpr operator bool() const
    {
        return static_cast<bool>(m_ptr);
    }

    constexpr bool operator!() const
    {
        return !static_cast<bool>(m_ptr);
    }

    constexpr Type& operator*() const
    {
        return *m_ptr;
    }

    constexpr Type* operator->() const
    {
        return m_ptr;
    }

    constexpr friend bool operator==(const SharedPtr<Type>& left, const SharedPtr<Type>& right)
    {
        return left.m_ptr == right.m_ptr;
    }

    //template<class Type>
    constexpr friend bool operator==(const Type* left, const SharedPtr<Type>& right)
    {
        return left == right.m_ptr;
    }

    //template<class Type>
    constexpr friend bool operator==(const SharedPtr<Type>& left, const Type* right)
    {
        return left.m_ptr == right;
    }

    //template<class Type>
    constexpr friend bool operator!=(const SharedPtr<Type>& left, const SharedPtr<Type>& right)
    {
        return left.m_ptr != right.m_ptr;
    }

    //template<class Type>
    constexpr friend bool operator!=(const Type* left, const SharedPtr<Type>& right)
    {
        return left != right.m_ptr;
    }

    //template<class Type>
    constexpr friend bool operator!=(const ScopePtr<Type>& left, const Type* right)
    {
        return left.m_ptr != right;
    }


private:
    // 原始指针
    Type* m_ptr = nullptr;

    // 引用计数
    RefCount<Type>* m_ref{};
};

template<Concept::ClassType Type, class... Args>
constexpr SharedPtr<Type> MakeShared(Args&&... args)
{
    return SharedPtr<Type>(new Type(std::forward<Args>(args)...));
}
}// namespace Star