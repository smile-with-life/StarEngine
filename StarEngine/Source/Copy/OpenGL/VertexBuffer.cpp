#include "starpch.h"
#include "VertexBuffer.h"
#include "OpenGLCommon.h"

namespace Star
{
VertexBuffer::VertexBuffer(const void* data, uint32 count, VertexType type)
    : m_count(count)
    , m_type(type)
{
    GLCall(glGenBuffers(1, &m_handle));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_handle));
    GLCall(glBufferData(GL_ARRAY_BUFFER, m_count * GetAttributeSize(), data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_handle));
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_handle));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

uint32 VertexBuffer::Count() const
{
	return m_count;
}

VertexType VertexBuffer::Type() const
{
	return m_type;
}

uint32 VertexBuffer::GetAttributeSize() const
{
	switch (m_type)
	{
	case VertexType::Position:		// 位置
		return sizeof(float) * 3;
	case VertexType::Texcoord:		// 纹理
		return sizeof(float) * 2;
	case VertexType::Normal:		// 法线
		return sizeof(float) * 3;
	case VertexType::Color:			// 颜色
		return sizeof(float) * 4;
	case VertexType::BoneIndex:		// 骨骼索引
		return sizeof(int) * 4;
	case VertexType::BoneWeight:	// 骨骼权重
		return sizeof(float) * 4;
	default:
		return 0;
	}
}
}// namespace Star
