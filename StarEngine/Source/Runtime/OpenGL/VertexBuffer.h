#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

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
	VertexBuffer() = delete;

	~VertexBuffer();

	VertexBuffer(const VertexBuffer& other) = delete;

	VertexBuffer& operator=(const VertexBuffer& other) = delete;

	VertexBuffer(VertexBuffer&& other) noexcept;

	VertexBuffer& operator=(VertexBuffer&& other) noexcept;

	VertexBuffer(int32 index);

	VertexBuffer(int32 index, void* data,uint32 count, VertexType type);

public:
	void Init(void* data, uint32 count, VertexType type);
private:
	uint32 GetVertexSize(VertexType type);
private:
	// 顶点属性位置索引
	int32 m_index;

	// 对象句柄 VBO
	Handle m_handle = 0;

	// 顶点数量
	uint32 m_count = 0;

	// 顶点类型
	VertexType m_type = VertexType::None;

};

}// namespace Star