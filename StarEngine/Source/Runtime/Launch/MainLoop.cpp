#include "starpch.h"

#include "MainLoop.h"

#include "Runtime/Test/Test.h"



namespace Star
{
MainLoop::MainLoop()
{
    m_app = Scope<Application>(Application::Create());
    m_renderer = Scope<OpenGL>(OpenGL::Create());
    m_sence = MakeScope<Sence>();
    m_frameManager = MakeScope<FrameManager>();
}

MainLoop::~MainLoop()
{

}

void MainLoop::Init()
{
    TESTING_INIT_BEGIN();
    m_app->Init();
    m_renderer->Init();
    m_renderer->CreateContext(m_app->GetWindowHandle());
    m_sence->Init();
    m_frameManager->Init();
    TESTING_INIT_END();
}

void MainLoop::Tick()
{  
    TESTING_TICK_BEGIN();
    m_frameManager->TickStart();

    m_app->Tick();
    m_renderer->Tick();
  
    m_frameManager->TickEnd();
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
