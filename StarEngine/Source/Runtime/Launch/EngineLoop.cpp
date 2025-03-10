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

int EngineLoop::Init()
{
    
    m_app->Init();
    Test::Test_File();
    Test::Test_Config();
    Test::Test_Shader();

    return 0;
}

void EngineLoop::Tick()
{   
    m_app->Tick();
}

void EngineLoop::Exit()
{
    m_app->Exit();
}

bool EngineLoop::IsQuit()
{
    return m_app->IsQuit();
}
}// namespace Star
