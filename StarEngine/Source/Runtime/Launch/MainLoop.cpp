#include "starpch.h"

#include "MainLoop.h"

#include "Runtime/Test/Test.h"
#include "Runtime/Core/File/File.h"



namespace Star
{
MainLoop::MainLoop()
{
    m_app = ScopePtr<Application>(Application::Create());
    m_renderer = ScopePtr<OpenGL>(OpenGL::Create());
    m_senceManager = MakeScope<SenceManager>();
    m_frameManager = MakeScope<FrameManager>();
    m_inputManager = MakeScope<InputManager>();
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
    m_senceManager->Init();
    m_frameManager->Init();
    m_inputManager->Init();
    TESTING_INIT_END();
    std::cout << File::AbsolutePath("./");
}

void MainLoop::Tick()
{  
    TESTING_TICK_BEGIN();
    
    // 帧开始
    m_frameManager->TickStart();
    m_senceManager->Tick();
    m_inputManager->Tick();
    m_renderer->Tick();
    m_app->Tick();
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
