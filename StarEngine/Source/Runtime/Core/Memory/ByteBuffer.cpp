#include"starpch.h"

#include "ByteBuffer.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
ByteBuffer::ByteBuffer(const char* data)
{
    int64 size = strlen(data);
    for (int64 i = 0; i < size; ++i)
    {
        m_data.PushBack(data[i]);
    }
}

ByteBuffer::ByteBuffer(const ByteBuffer& other)
    : m_data(other.m_data)
{

}

ByteBuffer& ByteBuffer::operator=(const ByteBuffer& other)
{
    if (&other == this) [[unlikely]] return *this;
    m_data = other.m_data;
    return *this;
}

ByteBuffer::ByteBuffer(ByteBuffer&& other) noexcept
    : m_data(std::move(other.m_data))
{

}

ByteBuffer& ByteBuffer::operator=(ByteBuffer&& other) noexcept
{
    if (&other == this) [[unlikely]] return *this;
    m_data = std::move(other.m_data);
    return *this;
}

char& ByteBuffer::operator[](int64 index)
{
    return m_data[index];
}

const char& ByteBuffer::operator[](int64 index) const
{
    return m_data[index];
}

void ByteBuffer::Add(const char* data, int64 size)
{
    for (int i = 0; i < size; ++i)
    {
        m_data.PushBack(data[i]);
    }
}

ByteBuffer& ByteBuffer::operator<<(char ch)
{
    m_data.Insert(m_data.end(), ch);
    return *this;
}

char* ByteBuffer::Data()
{
    return m_data.Data();
}

const char* ByteBuffer::Data() const
{
    return m_data.Data();
}

int64 ByteBuffer::Size() const
{
    return m_data.Size();
}

int64 ByteBuffer::Max() const
{
    return std::numeric_limits<int64>::max();
}

bool ByteBuffer::IsEmpty()
{
    return m_data.IsEmpty();
}

void ByteBuffer::Resize(int64 size)
{
    m_data.Resize(size);
}

void ByteBuffer::Clear()
{
    m_data.Clear();
}

void ByteBuffer::Swap(ByteBuffer& other)
{
    m_data.Swap(other.m_data);
}
}// namespace Star