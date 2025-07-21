#pragma once
#include "Core/Core.h"
#include "Core/Time/Time.h"

namespace Star
{
class FrameManager
{
public:
    void Init();

    void TickStart();

    void TickEnd();

    void Exit();
private:
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
}// namespace Star