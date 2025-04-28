#pragma once
#include "Runtime/Core/Time/Clock.h"
#include "Runtime/Core/Time/TimePoint.h"
#include "Runtime/Core/Time/Duration.h"
#include "Runtime/Core/Time/DateTime.h"

namespace Star::Time
{
void Delay(Seconds second);

void Delay(Milliseconds ms);

void Delay(Microseconds us);
}// namespace Star::Time