#include "starpch.h"
#include "Duration.h"

namespace Star
{
int64 Duration::Years() const
{
    auto years = std::chrono::duration_cast<std::chrono::years>(count);
    return years.count();
}

int64 Duration::Months() const
{
    auto months = std::chrono::duration_cast<std::chrono::months>(count);
    return months.count();
}

int64 Duration::Days() const
{
    auto days = std::chrono::duration_cast<std::chrono::days>(count);
    return days.count();
}

int64 Duration::Hours() const
{
    auto hours = std::chrono::duration_cast<std::chrono::hours>(count);
    return hours.count();
}

int64 Duration::Minutes() const
{
    auto min = std::chrono::duration_cast<std::chrono::minutes>(count);
    return min.count();
}

int64 Duration::Seconds() const
{
    auto s = std::chrono::duration_cast<std::chrono::seconds>(count);
    return s.count();
}

int64 Duration::Miliseconds() const
{
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(count);
    return ms.count();
}

int64 Duration::Mircoseconds() const
{
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(count);
    return us.count();
}

int64 Duration::Nanoseconds() const
{
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(count);
    return ns.count();
}
}// namespace Star