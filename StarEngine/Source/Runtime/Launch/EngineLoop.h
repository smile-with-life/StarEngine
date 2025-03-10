#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/AppFrame/Application/Application.h"

namespace Star {
class SE_API EngineLoop
{
public:
    EngineLoop();
    virtual ~EngineLoop();
public:
    virtual int Init();
    virtual void Tick();
    virtual void Exit();

    bool IsQuit();
private:
    Application* m_app = nullptr;
};

inline EngineLoop GEngineLoop;
}// namespace Star


