#pragma once

#include "Runtime/Core/Core.h"

#include "Runtime/Platform/Window.h"

namespace Star
{
class OpenGL
{
public:
    virtual void Init();

    virtual void Tick();

    virtual void Exit();

    virtual void CreateContext(void* windowHandle);
public:
    static OpenGL* Create();
};
}// namespace Star