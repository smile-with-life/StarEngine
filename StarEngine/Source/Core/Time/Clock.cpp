#include "starpch.h"
#include "Clock.h"

namespace Star
{
TimePoint<SystemClock> SystemClock::Now()
{
    auto time = std::chrono::system_clock::now();
    return TimePoint<SystemClock>(time);
}

TimePoint<SteadyClock> SteadyClock::Now()
{
    auto time = std::chrono::steady_clock::now();
    return TimePoint<SteadyClock>(time);
}
}// namespace Star