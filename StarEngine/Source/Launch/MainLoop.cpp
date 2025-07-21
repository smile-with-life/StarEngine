#include "starpch.h"

#include "MainLoop.h"

#include "Core/File/File.h"



namespace Star
{
MainLoop::MainLoop()
{
    m_app = ScopePtr<Application>(Application::Create());

    m_frameManager = MakeScope<FrameManager>();
}

MainLoop::~MainLoop()
{

}

void MainLoop::Init()
{
    m_app->Init();
    m_frameManager->Init();

    std::cout << File::AbsolutePath(".");

    // 初始化游戏引擎和UI系统
    
    m_ui.Init(m_app->GetWindowHandle()); // 确保此目录下有Ultralight的核心资源

    

}

void MainLoop::Tick()
{  
    
    // 帧开始
    m_frameManager->TickStart();
    m_app->Tick();
    m_ui.Tick();
    m_frameManager->TickEnd();

}

void MainLoop::Exit()
{
    m_app->Exit();
}

bool MainLoop::IsQuit()
{
    return m_app->IsQuit();
}
}// namespace Star
