#include "starpch.h"
#include "EngineLoop.h"

namespace Star {
int StarEngineLoop::PreInit()
{
    std::cout << "EnginePreInit" << std::endl;
    return 0;
}

int StarEngineLoop::Init()
{
    std::cout << "EngineInit" << std::endl;
    return 0;
}

void StarEngineLoop::Tick()
{
    for(int i=0;i<5;++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Tick" << std::endl;
    }
    m_requestingExit = true;
}

void StarEngineLoop::Exit()
{
    std::cout << "EngineExit" << std::endl;
}

bool StarEngineLoop::isRequestingExit()
{
    return m_requestingExit;
}
}//namespace Star
