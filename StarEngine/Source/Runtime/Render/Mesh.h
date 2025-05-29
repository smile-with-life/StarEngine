#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Container/Array.h"
#include "Runtime/Core/Memory/RAII.h"


namespace Star
{
class VertexBuffer;
class IndexBuffer;
enum class PrimitiveType
{
	None,
	Points,
	Lines,
	Triangles
};

class Mesh
{
public:
	Mesh();

	~Mesh();
public:
	void AddVertexBuffer(const VertexBuffer& vertexBuffer);

	void AddIndexBuffer(const IndexBuffer& indexBuffer);

	void Bind() const;

	void Unbind() const;

	uint32 IndexCount() const;

	void Render() const;
private:
	Array<VertexBuffer> m_vertexBuffers;
	Array<IndexBuffer> m_indexBuffers;
};
}// namespace Star