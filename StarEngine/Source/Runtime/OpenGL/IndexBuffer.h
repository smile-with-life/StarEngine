#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
class IndexBuffer
{
public:
	IndexBuffer(const uint32* data, uint32 count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int Count() const { return m_count; }
private:
	unsigned int m_handle;// EBO
	unsigned int m_count;
};
}// namespace Star
