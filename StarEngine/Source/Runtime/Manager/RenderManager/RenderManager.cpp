#include "starpch.h"
#include "RenderManager.h"

namespace Star
{
RenderManager::RenderManager()
{
    m_api = MakeShared<GraphicsAPI>();
}

RenderManager::~RenderManager()
{

}

void RenderManager::Init()
{
    m_api->Init();
}

void RenderManager::Tick()
{

}

void RenderManager::Exit()
{

}
}// namespace Star