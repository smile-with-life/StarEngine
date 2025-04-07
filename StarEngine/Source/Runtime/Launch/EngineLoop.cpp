#include "starpch.h"

#include "EngineLoop.h"

#include "Runtime/Test/Test.h"


namespace Star
{
EngineLoop::EngineLoop()
{
    m_app = Application::Create();
}

EngineLoop::~EngineLoop()
{
    delete m_app;
}

void EngineLoop::Init()
{
    TESTING_INIT_BEGIN();
    m_app->Init();
    TESTING_INIT_END();
}

void EngineLoop::Tick()
{  
    TESTING_TICK_BEGIN();
    m_app->Tick();
    TESTING_TICK_END();
}

void EngineLoop::Exit()
{
    TESTING_EXIT_BEGIN();
    m_app->Exit();
    TESTING_EXIT_END();
}

bool EngineLoop::IsQuit()
{
    return m_app->IsQuit();
}
}// namespace Star
