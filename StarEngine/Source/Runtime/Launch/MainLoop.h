#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Memory/RAII.h"
#include "Runtime/Platform/Application.h"
#include "Runtime/Core/Time/Time.h"
#include "Runtime/OpenGL/OpenGL.h"

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
    // 
    Scope<Application> m_app;

    // 渲染接口
    Scope<OpenGL> m_renderer;

    // 最大帧率限制
    int32 m_maxFPS = 30;

    // 帧间隔
    Microseconds m_frameTime = 33333;

    // 帧计数
    int32 m_frameCount = 0;

    // 帧率
    int32 m_FPS = 0;

    // 上次更新帧率的时间
    TimePoint<SteadyClock> m_lastUpdateTime;

    // 帧开始的时间
    TimePoint<SteadyClock> m_startTime;

    // 帧结束的时间
    TimePoint<SteadyClock> m_endTime;
};

inline MainLoop GMainLoop;
}// namespace Star


