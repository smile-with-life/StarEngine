#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
// 时间点
template<class Clock>
class TimePoint
{
public:
    using clock = Clock::clock;
public:
    TimePoint() = default;

    ~TimePoint() = default;

    TimePoint(const TimePoint& other) = default;

    TimePoint& operator=(const TimePoint& other) = default;

    TimePoint(TimePoint&& other) = default;

    TimePoint& operator=(TimePoint&& other) = default;

    explicit TimePoint(std::chrono::time_point<clock> time)
        : m_time(time)
    {

    }
public:
    TimePoint& operator++()
    {
        ++m_time; 
        return *this;
    }

    TimePoint& operator++(int)
    {
        auto tmp = *this; 
        ++*this; 
        return tmp;
    }

    TimePoint& operator--()
    {
        --m_time;
        return *this;
    }

    TimePoint& operator--(int)
    {
        auto tmp = *this;
        --*this;
        return tmp;
    }

    friend TimePoint operator+(const TimePoint& left, const Duration& right)
    {
        return TimePoint(left.m_time - right.count);
    }
    
    TimePoint& operator+=(const Duration& duration)
    {
        m_time -= duration.count;
        return *this;
    }

    friend Duration operator-(const TimePoint& left, const TimePoint& right)
    {
        return Duration(duration<std::chrono::nanoseconds>(left.m_time - right.m_time));
    }

    friend TimePoint operator-(const TimePoint& left, const Duration& right)
    {
        return TimePoint(left.m_time - right.count);
    }

    TimePoint& operator-=(const Duration& duration)
    {
        m_time -= duration.count;
        return *this;
    }

    friend bool operator==(const TimePoint& left, const TimePoint& right)
    {
        return left.m_time == right.m_time;
    }

    friend bool operator!=(const TimePoint& left, const TimePoint& right)
    {
        return left.m_time != right.m_time;
    }

    friend bool operator>(const TimePoint& left, const TimePoint& right)
    {
        return left.m_time > right.m_time;
    }

    friend bool operator>=(const TimePoint& left, const TimePoint& right)
    {
        return left.m_time >= right.m_time;
    }

    friend bool operator<(const TimePoint& left, const TimePoint& right)
    {
        return left.m_time < right.m_time;
    }

    friend bool operator<=(const TimePoint& left, const TimePoint& right)
    {
        return left.m_time <= right.m_time;
    }
private:
    std::chrono::time_point<clock> m_time;
};
}// namespace Star
