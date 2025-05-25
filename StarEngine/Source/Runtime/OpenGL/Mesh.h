#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/OpenGL/VertexBuffer.h"
#include "Runtime/OpenGL/IndexBuffer.h"

namespace Star
{
enum class PrimitiveType
{
	None
};

class Mesh
{
public:
	Mesh();

	~Mesh();
public:
	void AddVertexBuffer(const VertexBuffer& vertexBuffer);

	void SetIndexBuffer(const IndexBuffer& indexBuffer);

	void Bind() const;

	void Unbind() const;

	uint32 IndexCount() const;

	void Render() const;
private:
	uint32 m_handle = 0; // VAO

	uint32 m_index = 0; // 顶点属性布局索引

	uint32 m_indexCount = 0; // 索引数量

	PrimitiveType m_type = PrimitiveType::None;
};
}// namespace Star