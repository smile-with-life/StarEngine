#pragma once
#include "Core/Core.h"

namespace Star
{
class LogManager
{
public:
    LogManager() = default;
public:
    void Init(); 

    void Tick();

    void Exit();
};
}// namespace Star