#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
class IndexBuffer
{
public:
	IndexBuffer() = default;

	~IndexBuffer();

	IndexBuffer(const IndexBuffer& other) = delete;

	IndexBuffer& operator=(const IndexBuffer& other) = delete;

	IndexBuffer(IndexBuffer&& other) noexcept;

	IndexBuffer& operator=(IndexBuffer&& other) noexcept;

	IndexBuffer(void* data, uint32 count);
public:
	void UploadData(void* data, uint32 count);

	uint32 Count() const;
private:
	// 索引缓冲对象句柄
	Handle m_handle = 0;

	// 顶点数量
	uint32 m_count = 0;
};
}// namespace Star