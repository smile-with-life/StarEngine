#pragma once
#include "Core/Time/Clock.h"
#include "Core/Time/TimePoint.h"
#include "Core/Time/Duration.h"
#include "Core/Time/DateTime.h"

namespace Star::Time
{
void Delay(Seconds second);

void Delay(Milliseconds ms);

void Delay(Microseconds us);
}// namespace Star::Time