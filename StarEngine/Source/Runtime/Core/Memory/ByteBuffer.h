#pragma once

#include "Runtime/Core/Core.h"

#include "Runtime/Core/Container/Array.h"

namespace Star
{
class ByteBuffer
{
public:
    ByteBuffer() = default;

    ~ByteBuffer() = default;

    ByteBuffer(const char* data);

    ByteBuffer(const ByteBuffer& other);

    ByteBuffer& operator=(const ByteBuffer& other);

    ByteBuffer(ByteBuffer&& other) noexcept;

    ByteBuffer& operator=(ByteBuffer&& other) noexcept;
public:
    // 访问指定元素,不进行边界检查
    char& operator[](int64 index);

    // 访问指定元素,不进行边界检查
    const char& operator[](int64 index) const;

    // 向字节数组中写入数据
    void Add(const char* data, int64 size);

    ByteBuffer& operator<<(char ch);

    char* Data();

    const char* Data() const;

    // 返回数组的元素个数
    int64 Size() const;

    // 返回数组的最大元素个数
    int64 Max() const;

    // 判断数组是否为空
    bool IsEmpty();

    // 改变存储元素的个数
    void Resize(int64 size);

    // 清空数组,实际内存并不释放
    void Clear();

    // 交换内容
    void Swap(ByteBuffer& other);
private:
    Array<char> m_data;
};
}// namespace Star