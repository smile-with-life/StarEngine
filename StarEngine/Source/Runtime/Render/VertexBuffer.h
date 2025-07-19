#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
enum class VertexAttributeType
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
    VertexBuffer(const void* data, uint32 size, VertexAttributeType type);

    ~VertexBuffer();
public:
    VertexAttributeType Type() const;
private:
    VertexAttributeType m_type = VertexAttributeType::None;
    const byte* m_data;
    const uint32 m_size;
};
}// namespace Star