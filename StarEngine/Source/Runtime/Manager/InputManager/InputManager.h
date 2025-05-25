#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
class InputManager
{
public:
    InputManager() = default;
public:
    void Init();

    void Tick();

    void Exit();
};
}// namespace Star