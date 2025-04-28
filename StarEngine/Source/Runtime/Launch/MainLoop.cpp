#include "starpch.h"

#include "MainLoop.h"

#include "Runtime/Test/Test.h"



namespace Star
{
MainLoop::MainLoop()
{
    m_app = Scope<Application>(Application::Create());
    m_lastUpdateTime = SteadyClock::Now();
}

MainLoop::~MainLoop()
{

}

void MainLoop::Init()
{
    TESTING_INIT_BEGIN();
    m_app->Init();
    TESTING_INIT_END();
}

void MainLoop::Tick()
{  
    TESTING_TICK_BEGIN();

    auto start = SteadyClock::Now();
    {
        m_startTime = SteadyClock::Now();
        m_app->Tick();

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
    auto end = SteadyClock::Now();
    auto time = end - start;
    //std::cout <<"第" << m_frameCount <<"帧执行时间:" << time.Count() / 1000000 << "ms\n";
    
    TESTING_TICK_END();
}

void MainLoop::Exit()
{
    TESTING_EXIT_BEGIN();
    m_app->Exit();
    TESTING_EXIT_END();
}

bool MainLoop::IsQuit()
{
    return m_app->IsQuit();
}
}// namespace Star
