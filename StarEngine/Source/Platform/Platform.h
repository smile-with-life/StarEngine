#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Time/Duration.h"

namespace Star
{
class Platform
{
public:
    // 高精度延时函数
    virtual void HighAccuracyDelay(Microseconds us);
public:
    Platform* Create();
};

inline Platform* OS = nullptr;

inline void Delay(Microseconds us)
{
    OS->HighAccuracyDelay(us);
}
}//namespace Star

