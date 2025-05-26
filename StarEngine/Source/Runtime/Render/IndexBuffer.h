#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
class IndexBuffer
{
public:
	IndexBuffer(const void* data, uint32 count);
	~IndexBuffer();
public:
	uint32 Count() const { return m_count; }
private:
	const byte* m_data;
	const uint32 m_count;
};
}// namespace Star