#pragma once
#include"Runtime/Core/Core.h"
#include"Runtime/Core/Concept/Concept.h"
#include<atomic>

namespace Star
{
// 独占指针
template<Concept::ClassType Type>
class Scope
{
public:
    constexpr Scope() = default;

    constexpr ~Scope()
    {
        if(m_ptr)
        {
            delete m_ptr;
        }
    }

    constexpr Scope(const Scope& other) = delete;

    constexpr Scope& operator=(const Scope& other) = delete;

    constexpr Scope(Scope&& other) noexcept
        : m_ptr(other.m_ptr)
    {
        other.m_ptr = nullptr;
    }

    constexpr Scope& operator=(Scope&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        return *this;
    }

    constexpr explicit Scope(Type* ptr) noexcept
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

    constexpr void Swap(Scope& other) noexcept
    {
        std::swap(m_ptr, other.m_ptr);
    }
public:
    constexpr Scope& operator=(std::nullptr_t) noexcept
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

    constexpr friend bool operator==(const Scope<Type>& left, const Scope<Type>& right)
    {
        return left.m_ptr == right.m_ptr;
    }

    template<class Type>
    constexpr friend bool operator==(const Type* left, const Scope<Type>& right)
    {
        return left== right.m_ptr;
    }

    template<class Type>
    constexpr friend bool operator==(const Scope<Type>& left, const Type* right)
    {
        return left.m_ptr == right;
    }

    template<class Type>
    constexpr friend bool operator!=(const Scope<Type>& left, const Scope<Type>& right)
    {
        return left.m_ptr != right.m_ptr;
    }

    template<class Type>
    constexpr friend bool operator!=(const Type* left, const Scope<Type>& right)
    {
        return left != right.m_ptr;
    }

    template<class Type>
    constexpr friend bool operator!=(const Scope<Type>& left, const Type* right)
    {
        return left.m_ptr != right;
    }
private:
    Type* m_ptr = nullptr;
};

template<Concept::ClassType Type, class... Args>
constexpr Scope<Type> MakeScope(Args&&... args)
{
    return Scope<Type>(new Type(std::forward<Type>(args)...));
}

// 共享指针
template<Concept::ClassType Type>
class Shared
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
    Shared() = default;

    ~Shared()
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
    
    Shared(const Shared& other)
        : m_ptr(other.m_ptr), m_ref(other.m_ref)
    {     
        if (m_ref)
        {
            m_ref->Increase();
        }     
    }

    Shared& operator=(const Shared& other)
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
        m_ptr = other.ptr_;
        m_ref = other.m_ref;
        if (m_ref) 
        {
            m_ref->Increase();
        }
        return *this;
    }

    Shared(Shared&& other) noexcept
        : m_ptr(other.m_ptr), m_ref(other.m_ref)
    {
        other.m_ptr = nullptr;
        other.m_ref = nullptr;
    }

    Shared& operator=(Shared&& other) noexcept
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

    explicit Shared(Type* ptr)
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

    constexpr void Swap(Shared& other) noexcept
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

    constexpr friend bool operator==(const Shared<Type>& left, const Shared<Type>& right)
    {
        return left.m_ptr == right.m_ptr;
    }

    template<class Type>
    constexpr friend bool operator==(const Type* left, const Shared<Type>& right)
    {
        return left == right.m_ptr;
    }

    template<class Type>
    constexpr friend bool operator==(const Shared<Type>& left, const Type* right)
    {
        return left.m_ptr == right;
    }

    template<class Type>
    constexpr friend bool operator!=(const Shared<Type>& left, const Shared<Type>& right)
    {
        return left.m_ptr != right.m_ptr;
    }

    template<class Type>
    constexpr friend bool operator!=(const Type* left, const Shared<Type>& right)
    {
        return left != right.m_ptr;
    }

    template<class Type>
    constexpr friend bool operator!=(const Scope<Type>& left, const Type* right)
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
constexpr Shared<Type> MakeShared(Args&&... args)
{
    return Shared<Type>(new Type(std::forward<Type>(args)...));
}
}// namespace Star