#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Time/TimePoint.h"

namespace Star
{
// 系统时钟
class SystemClock
{
public:
    using clock = std::chrono::system_clock;
public:
    SystemClock() = default;
    ~SystemClock() = default;
public:
    static TimePoint<SystemClock> Now();
};

// 单调时钟
class SteadyClock
{
public:
    using clock = std::chrono::steady_clock;
public:
    SteadyClock() = default;
    ~SteadyClock() = default;
public:
    static TimePoint<SteadyClock> Now();
};


}// namespace Star