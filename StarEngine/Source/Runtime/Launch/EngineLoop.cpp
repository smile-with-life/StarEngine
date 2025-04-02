#include "starpch.h"

#include "EngineLoop.h"

#include "Runtime/Test/Test.h"


namespace Star
{
EngineLoop::EngineLoop()
{
    m_app = Application::Create();
    Test::UnitTesting();
}

EngineLoop::~EngineLoop()
{
    delete m_app;
}

void EngineLoop::Init()
{
    m_app->Init();
    Test::UnitTesting_Init();
}

void EngineLoop::Tick()
{  
    Test::UnitTesting_Tick();
    m_app->Tick();
}

void EngineLoop::Exit()
{
    Test::UnitTesting_Exit();
    m_app->Exit();
}

bool EngineLoop::IsQuit()
{
    return m_app->IsQuit();
}
}// namespace Star
