#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Memory/RAII.h"
#include "Buffer.h"

namespace Star
{
// 图形渲染设备
class Device
{
public:
    Device();

    virtual ~Device();
public:
    // 创建缓冲区资源
    virtual ScopePtr<Buffer> CreateBuffer(const BufferDesc& desc);

    // 

    // 返回图形渲染设备所使用的后端图形API
    virtual GraphicAPIType BackendType() const;
public:
    static Device* Create(GraphicAPIType type);
};
}// namespace Star