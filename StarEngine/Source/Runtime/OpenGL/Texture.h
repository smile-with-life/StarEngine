#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Image/Image.h"

namespace Star
{
// 纹理
class Texture
{
public:
    Texture() = default;

    ~Texture() = default;

    Texture(const Texture& other) = delete;

    Texture& operator=(const Texture& other) = delete;

    Texture(Texture&& other) noexcept;

    Texture& operator=(Texture&& other) noexcept;
public:
    void Upload(uint32 index, const Image& image);

    void Use() const;
private:
    // 纹理对象句柄
    Handle m_handle = 0;

    // 索引
    uint32 m_index = 0;
};
}// namespace Star