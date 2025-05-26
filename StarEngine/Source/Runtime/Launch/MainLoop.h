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
    ScopePtr<Application> m_app;

    // 渲染模块
    ScopePtr<OpenGL> m_renderer;

    // 场景管理器
    ScopePtr<SenceManager> m_senceManager;

    // 输入管理器
    ScopePtr<InputManager> m_inputManager;

    // 帧管理器
    ScopePtr<FrameManager> m_frameManager;
};

inline MainLoop GMainLoop;
}// namespace Star


