#include "starpch.h"
#include "Clock.h"

namespace Star
{
Time Clock::NowTime()
{
    return Time(clock::now());
}
}// namespace Star