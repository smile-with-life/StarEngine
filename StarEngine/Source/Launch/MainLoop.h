#pragma once

#include "Core/Core.h"
#include "Core/Memory/RAII.h"
#include "Platform/Application.h"
#include "Core/Time/Time.h"
#include "Manager/FrameManager/FrameManager.h"
#include "Manager/InputManager/InputManager.h"

#include "UI/UIEngine.h"

namespace Star {
class CORE_API MainLoop
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

    // 帧管理器
    ScopePtr<FrameManager> m_frameManager;

    GameUI m_ui;
};

inline MainLoop GMainLoop;
}// namespace Star


