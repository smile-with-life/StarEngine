#include"starpch.h"

#include "ByteBuffer.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
ByteArray::ByteArray(const char* data)
{
    int64 size = strlen(data);
    for (int64 i = 0; i < size; ++i)
    {
        m_data.PushBack(data[i]);
    }
}

ByteArray::ByteArray(const ByteArray& other)
    : m_data(other.m_data)
{

}

ByteArray& ByteArray::operator=(const ByteArray& other)
{
    if (&other == this) [[unlikely]] return *this;
    m_data = other.m_data;
    return *this;
}

ByteArray::ByteArray(ByteArray&& other) noexcept
    : m_data(std::move(other.m_data))
{

}

ByteArray& ByteArray::operator=(ByteArray&& other) noexcept
{
    if (&other == this) [[unlikely]] return *this;
    m_data = std::move(other.m_data);
    return *this;
}

char& ByteArray::operator[](int64 index)
{
    return m_data[index];
}

const char& ByteArray::operator[](int64 index) const
{
    return m_data[index];
}

void ByteArray::Add(const char* data, int64 size)
{
    for (int i = 0; i < size; ++i)
    {
        m_data.PushBack(data[i]);
    }
}

ByteArray& ByteArray::operator<<(char ch)
{
    m_data.Insert(m_data.end(), ch);
    return *this;
}

char* ByteArray::Data()
{
    return m_data.Data();
}

const char* ByteArray::Data() const
{
    return m_data.Data();
}

int64 ByteArray::Size() const
{
    return m_data.Size();
}

int64 ByteArray::Max() const
{
    return std::numeric_limits<int64>::max();
}

bool ByteArray::IsEmpty()
{
    return m_data.IsEmpty();
}

void ByteArray::Resize(int64 size)
{
    m_data.Resize(size);
}

void ByteArray::Clear()
{
    m_data.Clear();
}

void ByteArray::Swap(ByteArray& other)
{
    m_data.Swap(other.m_data);
}
}// namespace Star