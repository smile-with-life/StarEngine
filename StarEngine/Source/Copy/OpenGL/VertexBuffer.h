#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
enum class VertexType
{
    None = 0,		// 默认值
    Position,		// 位置属性 3*float 
    Texcoord,		// 纹理坐标属性 2*float
    Normal,			// 法线属性 3*float
    Color,			// 颜色属性 4*float
    BoneIndex,		// 骨骼索引属性 4*int
    BoneWeight,     // 骨骼权重属性 4*float
};

class VertexBuffer
{
public:
    VertexBuffer(const void* data, uint32 size, VertexType type);

    ~VertexBuffer();

    void Bind() const;

    void Unbind() const;

    uint32 Count() const;

    VertexType Type() const;
private:
    uint32 GetAttributeSize() const;
private:
    Handle m_handle = 0;
    uint32 m_count = 0;
    VertexType m_type = VertexType::None;
};
}// namespace Star
