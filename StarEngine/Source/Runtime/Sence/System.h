#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
class System
{
public:
    virtual void Init();

    virtual void Tick();

    virtual void Exit();
};
}// namespace Star