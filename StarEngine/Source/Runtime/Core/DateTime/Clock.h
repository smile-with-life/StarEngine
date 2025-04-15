#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/DateTime/Time.h"

namespace Star
{
// 高精度时钟
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