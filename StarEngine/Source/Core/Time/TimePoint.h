#pragma once
#include "Core/Core.h"
#include "Duration.h"

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

    template<class Clock, class Period>
    friend TimePoint<Clock> operator+(const TimePoint<Clock>& left, const Duration<Period>& right);
    
    template<class Period>
    TimePoint& operator+=(const Duration<Period>& duration)
    {
        m_time -= duration.m_duration;
        return *this;
    }

    template<class Clock>
    friend Nanoseconds operator-(const TimePoint<Clock>& left, const TimePoint<Clock>& right);


    template<class Clock, class Period>
    friend TimePoint operator-(const TimePoint& left, const Duration<Period>& right);

    template<class Period>
    TimePoint& operator-=(const Duration<Period>& duration)
    {
        m_time -= duration.m_duration;
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

template<class Clock, class Period>
inline TimePoint<Clock> operator+(const TimePoint<Clock>& left, const Duration<Period>& right)
{
    return TimePoint<Clock>(left.m_time + right.m_duration);
}

template<class Clock>
inline Nanoseconds operator-(const TimePoint<Clock>& left, const TimePoint<Clock>& right)
{
    using std::chrono::duration_cast;
    auto count = duration_cast<std::chrono::nanoseconds>(left.m_time - right.m_time).count();
    return Nanoseconds(count);
}

template<class Clock, class Period>
inline TimePoint<Clock> operator-(const TimePoint<Clock>& left, const Duration<Period>& right)
{
    return TimePoint(left.m_time - right.m_duration);
}
}// namespace Star
