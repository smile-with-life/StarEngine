#include "starpch.h"
#include "IndexBuffer.h"

#include"glad/glad.h"

namespace Star
{
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_handle);
}

IndexBuffer::IndexBuffer(IndexBuffer&& other) noexcept
    : m_handle(other.m_handle)
    , m_count(other.m_count)
{
    other.m_handle = 0;
    other.m_count = 0;
}

IndexBuffer& IndexBuffer::operator=(IndexBuffer&& other) noexcept
{
    m_handle = other.m_handle;
    m_count = other.m_count;

    other.m_handle = 0;
    other.m_count = 0;
}

IndexBuffer::IndexBuffer(void* data, uint32 count)
    : m_count(count)
{
    UploadData(data, count);
}

void IndexBuffer::UploadData(void* data, uint32 count)
{
    m_count = count;
    glGenBuffers(1, &m_handle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * 4, data, GL_STATIC_DRAW);

}

uint32 IndexBuffer::Count() const
{
    return m_count;
}

}// namespace Star