#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Memory/RAII.h"
#include "Runtime/GraphicsAPI/GraphicsAPI.h"

namespace Star
{
class RenderManager
{
public:
    RenderManager();

    ~RenderManager();
public:
    void Init();

    void Tick();

    void Exit();
private:
    SharedPtr<GraphicsAPI> m_api;
};
}// namespace Star