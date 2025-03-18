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

// 顶点属性
class VertexAttribute
{
public:
	VertexAttribute() = default;
	~VertexAttribute() = default;
private:
	String m_name;
	VertexType m_type;
	uint32 m_size;
	bool m_isNormalized;
};
class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	void Bind();
	void Unbind();
private:

	Handle m_id;
	// 顶点数量
	uint32 m_vertexCount;

	// 顶点类型
	VertexType m_type;

};
}// namespace Star