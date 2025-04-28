#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Time/Duration.h"

namespace Star
{
class Platform
{
public:
    static Platform* Create();
};

inline Platform* OS = nullptr;
}//namespace Star

