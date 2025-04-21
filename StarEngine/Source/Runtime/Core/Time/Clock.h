#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Time/Time.h"

namespace Star
{
// 单调时钟
class Clock
{
public:
    using clock = std::chrono::steady_clock;
public:
    Clock() = default;
    ~Clock() = default;
public:
    static Time NowTime();
};


}// namespace Star