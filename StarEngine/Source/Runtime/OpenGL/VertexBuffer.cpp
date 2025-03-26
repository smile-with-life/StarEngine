#include "starpch.h"
#include "VertexBuffer.h"

#include"glad/glad.h"

namespace Star
{
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_handle);
}

VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept
	: m_index(other.m_index)
	, m_handle(other.m_handle)
	, m_count(other.m_count)
	, m_type(other.m_type)
{
	other.m_index = 0;
	other.m_handle = 0;
	other.m_count = 0;
	other.m_type = VertexType::None;
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept
{
	if (this == &other) [[unlikely]]
	{
		return *this;
	}

	m_index = other.m_index;
	m_handle = other.m_handle;
	m_count = other.m_count;
	m_type = other.m_type;

	other.m_index = 0;
	other.m_handle = 0;
	other.m_count = 0;
	other.m_type = VertexType::None;

	return *this;

}

VertexBuffer::VertexBuffer(int32 index)
	: m_index(index)
{

}

VertexBuffer::VertexBuffer(int32 index, void* data, uint32 count, VertexType type)
	: m_index(index)
{
	Init(data, count, type);
}

void VertexBuffer::Init(void* data, uint32 count, VertexType type)
{
	m_count = count;
	m_type = type;
	uint64 size = GetVertexSize(type) * count;
	glGenBuffers(1, &m_handle);
	glBindBuffer(GL_ARRAY_BUFFER, m_handle);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(m_index);

	switch (type)
	{
	case VertexType::None:
	{
		Assert(false);
		break;
	}
	case VertexType::Position :		// 位置
	{
		glVertexAttribPointer(m_index, 3, GL_FLOAT, false, 0, 0);
		break;
	}
	case VertexType::Texcoord :		// 纹理
	{
		glVertexAttribPointer(m_index, 2, GL_FLOAT, false, 0, 0);
		break;
	}
	case VertexType::Normal :		// 法线
	{
		glVertexAttribPointer(m_index, 3, GL_FLOAT, false, 0, 0);
		break;
	}
	case VertexType::Color :			// 颜色
	{
		glVertexAttribPointer(m_index, 4, GL_FLOAT, false, 0, 0);
		break;
	}
	default:
		Assert(false);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

uint32 VertexBuffer::GetVertexSize(VertexType type)
{
	switch (type)
	{
	case VertexType::Position :		// 位置
		return sizeof(float) * 3;
	case VertexType::Texcoord :		// 纹理
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