#include "starpch.h"
#include "IndexBuffer.h"

#include "OpenGLCommon.h"
namespace Star
{
IndexBuffer::IndexBuffer(const uint32* data, uint32 count)
    : m_count(count)
{
    Assert(sizeof(uint32) == sizeof(GLuint));

    GLCall(glGenBuffers(1, &m_handle));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_handle));
}

void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle));
}

void IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
}// namespace Satr
