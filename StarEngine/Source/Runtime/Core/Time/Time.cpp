#include "starpch.h"
#include "Time.h"

namespace Star
{
Time::Time(std::chrono::time_point<std::chrono::steady_clock> time)
    : m_time(time)
{

}
bool operator==(const Time& left, const Time& right)
{
    return left.m_time == right.m_time;
}
bool operator!=(const Time& left, const Time& right)
{
    return left.m_time != right.m_time;
}
bool operator>(const Time& left, const Time& right)
{
    return left.m_time > right.m_time;
}
bool operator>=(const Time& left, const Time& right)
{
    return left.m_time >= right.m_time;
}
bool operator<(const Time& left, const Time& right)
{
    return left.m_time < right.m_time;
}
bool operator<=(const Time& left, const Time& right)
{
    return left.m_time <= right.m_time;
}
Time operator+(const Time& time, const Years& years)
{
    return Time();
}
Time operator+(const Time& time, const Months& months)
{
    return Time();
}
Time operator+(const Time& time, const Days& days)
{
    return Time();
}
Time operator+(const Time& time, const Hours& hours)
{
    return Time();
}
Time operator+(const Time& time, const Minutes& minutes)
{
    return Time();
}
Time operator+(const Time& time, const Seconds& seconds)
{
    return Time();
}
Time operator+(const Time& time, const Miliseconds& ms)
{
    return Time();
}
Time operator+(const Time& time, const Mircoseconds& us)
{
    return Time();
}
Time operator+(const Time& time, const Nanoseconds& ns)
{
    return Time();
}
Duration operator-(const Time& left, const Time& right)
{
    return Duration();
}
}// namespace Star