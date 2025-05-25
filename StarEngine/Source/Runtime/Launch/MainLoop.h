#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Memory/RAII.h"
#include "Runtime/Platform/Application.h"
#include "Runtime/Core/Time/Time.h"
#include "Runtime/OpenGL/OpenGL.h"
#include "Runtime/Sence/Sence.h"
#include "Runtime/Manager/FrameManager/FrameManager.h"
#include "Runtime/Manager/SenceManager/SenceManager.h"
#include "Runtime/Manager/InputManager/InputManager.h"

namespace Star {
class SE_API MainLoop
{
public:
    MainLoop();
    virtual ~MainLoop();
public:
    virtual void Init();
    virtual void Tick();
    virtual void Exit();

    bool IsQuit();
private:
    // 应用程序模块
    Scope<Application> m_app;

    // 渲染模块
    Scope<OpenGL> m_renderer;

    // 场景管理器
    Scope<SenceManager> m_senceManager;

    // 输入管理器
    Scope<InputManager> m_inputManager;

    // 帧管理器
    Scope<FrameManager> m_frameManager;
};

inline MainLoop GMainLoop;
}// namespace Star


