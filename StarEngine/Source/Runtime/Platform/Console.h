#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Memory/RAII.h"

namespace Star
{

class Console
{ 
public:
    Console() = default;
    virtual ~Console() = default;

    virtual void Init();

    virtual void Tick();

    virtual void Exit();
public:
    static Console* Create();
};

}// namespace Star