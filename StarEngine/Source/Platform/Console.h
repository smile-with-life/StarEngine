#pragma once

#include "Core/Core.h"
#include "Core/Memory/RAII.h"

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