#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/GraphicsAPI/GraphicsAPI.h"

namespace Star
{
// 图形API
class OpenGLAPI:public GraphicsAPI
{
public:
    OpenGLAPI();

    virtual ~OpenGLAPI();

    void Init()
    {

    }
public:
    // 清理不再使用的资源
    virtual void Purge() noexcept
    {

    }

    //
};
}// namespace Star