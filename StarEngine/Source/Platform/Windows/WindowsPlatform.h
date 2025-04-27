#pragma once
#include "Runtime/Core/Core.h"
#include "Platform/Platform.h"
#include "Runtime/Core/Time/Duration.h"

namespace Star
{
class WindowsPlatform: public Platform
{
public:
    virtual void HighAccuracyDelay();
};

    
}// namespace Star