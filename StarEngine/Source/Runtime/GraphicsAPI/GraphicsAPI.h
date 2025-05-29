#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
// 图形API
class GraphicsAPI
{
public:
    GraphicsAPI();

    virtual ~GraphicsAPI();

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