#include "starpch.h"
#include "FrameManager.h"

namespace Star
{
void FrameManager::Init()
{
    m_lastUpdateTime = SteadyClock::Now();
}

void FrameManager::TickStart()
{
    m_startTime = SteadyClock::Now();
}

void FrameManager::TickEnd()
{
    m_endTime = SteadyClock::Now();

    auto currentFrameTime = ConvertType<Microseconds>(m_endTime - m_startTime);
    auto waitTime = m_frameTime - currentFrameTime;
    if (waitTime > Microseconds(0))
    {
        Time::Delay(waitTime);
    }
    m_frameCount++;

    auto now = SteadyClock::Now();
    auto updateTime = now - m_lastUpdateTime;
    if (updateTime >= Seconds(1))
    {
        m_FPS = m_frameCount;
        m_lastUpdateTime = now;
        m_frameCount = 0;
        std::cout << "帧率：" << m_FPS << "\n";
    }
}

void FrameManager::Exit()
{

}
}// namespace Star
