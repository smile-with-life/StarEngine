#pragma once

#include "Runtime/Core/Core.h"

#include "Runtime/AppFrame/Window/Window.h"

namespace Star
{
class OpenGL
{
public:
    virtual void Init(Window* window);

    virtual void Tick();

    virtual void Exit();
public:
    static OpenGL* Create();
};
}// namespace Star