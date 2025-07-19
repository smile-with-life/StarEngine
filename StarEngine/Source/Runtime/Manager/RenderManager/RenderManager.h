#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Memory/RAII.h"
#include "Runtime/GraphicAPI/Device.h"
#include "Runtime/Render/Viewport.h"

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

   void SetViewport();
private:
    // 图形API
    SharedPtr<Device> m_api;

    // 视口属性
    Viewport m_viewport;

    // 交换链
};
}// namespace Star