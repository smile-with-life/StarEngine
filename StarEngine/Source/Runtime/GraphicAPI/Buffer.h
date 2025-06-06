#pragma once
#include "Runtime/Core/Core.h"
#include "Common.h"

namespace Star
{
// 缓冲区类型
enum class BufferType
{
    None,
    Index,      // 索引缓冲区
    Vertex,     // 顶点缓冲区
    Uniform,    // 统一缓冲区
    Storage,    // 存储缓冲区
};
// 缓冲区的创建参数
struct BufferDesc
{
    const void* Data;       // 数据指针
    int32 Size;             // 缓冲区大小
    MemoryMode Mode;       // 存储模式
    BufferType Type;        // 缓冲区类型

    // 构造函数
    BufferDesc(BufferType type = BufferType::None,
        const void* data = nullptr,
        int32 size = 0,
        MemoryMode mode = MemoryMode::Private)
        : Data(data)
        , Size(size)
        , Mode(mode)
        , Type(type)
    {

    }
};
// 缓冲区接口
class Buffer
{
public:
    Buffer() = default;

    virtual ~Buffer() = default;
public:
    // 把资源上传到显存
    virtual bool Upload(const void* data, int32 size, uintptr_t offset);
    // 从显存中销毁资源
    virtual void Destory();
    // 资源存储模式
    virtual MemoryMode Mode();
    // 缓冲区的大小
    virtual int32 Size();
    // 缓冲区类型
    virtual BufferType Type();
};
}// namespace Star