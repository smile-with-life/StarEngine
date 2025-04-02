#include "starpch.h"

#include "Texture.h"
#include"glad/glad.h"

namespace Star
{
Texture::Texture(Texture&& other) noexcept
    : m_handle(other.m_handle)
{
    other.m_handle = 0;
}

Texture& Texture::operator=(Texture&& other) noexcept
{
    if (this == &other) [[unlikely]]
    {
        return *this;
    }

    m_handle = other.m_handle;
    other.m_handle = 0;
    return *this;
}

void Texture::Upload(uint32 index, const Image& image)
{
    uint32 width = image.Width();
    uint32 height = image.Height();
    const uint8* data = image.Data();
    uint16 format = 0;
    switch (image.Format())
    {
    case ImageFormat::R8:
    {
        format = GL_R;
        break;
    }
    case ImageFormat::RG8:
    {
        format = GL_RG;
        break;
    }
    case ImageFormat::RGB8:
    {
        format = GL_RGB;
        break;
    }
    case ImageFormat::RGBA8:
    {
        format = GL_RGBA;
        break;
    }
    }

    glGenTextures(1, &m_handle);
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, m_handle);

    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// 水平环绕模式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);// 垂直环绕模式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);// 缩小过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// 放大过滤

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    // 当前绑定的纹理自动生成所有需要的多级渐远纹理
    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::Use() const
{
    glBindTexture(GL_TEXTURE_2D, m_handle);
}

}// namespace Star