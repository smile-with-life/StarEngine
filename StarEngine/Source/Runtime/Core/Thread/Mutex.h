#pragma once
#include "Runtime/Core/Core.h"
#include <mutex>
#include<shared_mutex>

namespace Star
{
/* 自旋锁 */
class Spin
{
public:
    Spin() noexcept = default;
    ~Spin() = default;

    Spin(const Spin&) = delete;
    Spin& operator=(const Spin&) = delete;

    void Lock()
    {
        while (m_flag.test_and_set());
    }

    void Unlock()
    {
        m_flag.clear();
    }
private:
    std::atomic_flag m_flag;
};

/* 互斥锁 */
class Mutex
{
public:
    Mutex() noexcept = default;
    ~Mutex() = default;

    Mutex(const Mutex&) = delete;
    Mutex& operator=(const Mutex&) = delete;

    void Lock()
    {
        m_mutex.lock();
    }

    bool TryLock()
    {
        return m_mutex.try_lock();
    }

    void Unlock()
    {
        m_mutex.unlock();
    }
private:
    std::mutex m_mutex;
};

/* 读写锁 */
class RWMutex
{
public:
    RWMutex() noexcept = default;
    ~RWMutex() = default;

    RWMutex(const RWMutex&) = delete;
    RWMutex& operator=(const RWMutex&) = delete;

    void LockRead()
    {
        m_mutex.lock_shared();
    }

    bool TryLockRead()
    {
        return m_mutex.try_lock_shared();
    }

    void UnlockRead()
    {
        m_mutex.unlock_shared();
    }

    void LockWrite()
    {
        m_mutex.lock();
    }

    bool TryLockWrite()
    {
        return m_mutex.try_lock();
    }

    void UnlockWrite()
    {
        m_mutex.unlock();
    }
private:
    std::shared_mutex m_mutex;
};
}// namespace Star