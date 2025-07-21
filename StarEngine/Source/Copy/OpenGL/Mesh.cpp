#include "starpch.h"
#include "Mesh.h"
#include "OpenGLCommon.h"

namespace Star
{
Mesh::Mesh()
{
    glGenVertexArrays(1, &m_handle);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_handle);
}

void Mesh::AddVertexBuffer(const VertexBuffer& vertexBuffer)
{
    glBindVertexArray(m_handle);
    vertexBuffer.Bind();
    switch (vertexBuffer.Type())
    {
    case VertexType::Position:
    {
        glVertexAttribPointer(m_index, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(m_index);
        m_index++;
        break;
    }
    case VertexType::Color:
    {
        glVertexAttribPointer(m_index, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(m_index);
        m_index++;
        break;
    }
    case VertexType::Texcoord:
    {
        glVertexAttribPointer(m_index, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(m_index);
        m_index++;
        break;
    }
    }
}

void Mesh::SetIndexBuffer(const IndexBuffer& indexBuffer)
{
    glBindVertexArray(m_handle);
    indexBuffer.Bind();
    m_indexCount = indexBuffer.Count();
}

void Mesh::Bind() const
{
    glBindVertexArray(m_handle);
}

void Mesh::Unbind() const
{
    glBindVertexArray(0);
}

uint32 Mesh::IndexCount() const
{
    return m_indexCount;
}

void Mesh::Render() const
{
    if(m_indexCount)
    {
        GLCall(glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr));
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0x00, 36);
    }
}
}// namespace Star