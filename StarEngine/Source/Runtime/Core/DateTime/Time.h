#pragma once
#include "Runtime/Core/Core.h"

#include "Duration.h"

namespace Star
{
// 时间类
class Time
{
public:
    using clock = std::chrono::steady_clock;
    using time_point = std::chrono::time_point<clock>;
public:
    Time() = default;

    ~Time() = default;

    Time(const Time& other) = default;

    Time& operator=(const Time& other) = default;

    Time(Time&& other) = default;

    Time& operator=(Time&& other) = default;

    Time(time_point time);
public:
    friend bool operator==(const Time& left, const Time& right);

    friend bool operator!=(const Time& left, const Time& right);

    friend bool operator>(const Time& left, const Time& right);

    friend bool operator>=(const Time& left, const Time& right);

    friend bool operator<(const Time& left, const Time& right);

    friend bool operator<=(const Time& left, const Time& right);

    friend Time operator+(const Time& time, const Years& years);

    friend Time operator+(const Time& time, const Months& months);

    friend Time operator+(const Time& time, const Days& days);

    friend Time operator+(const Time& time, const Hours& hours);

    friend Time operator+(const Time& time, const Minutes& minutes);

    friend Time operator+(const Time& time, const Seconds& seconds);

    friend Time operator+(const Time& time, const Miliseconds& ms);

    friend Time operator+(const Time& time, const Mircoseconds& us);

    friend Time operator+(const Time& time, const Nanoseconds& ns);
private:
    time_point m_time{};
};
}// namespace Star