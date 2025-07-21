#include "starpch.h"
#include "Texture.h"
#include "OpenGLCommon.h"
#include <stb/stb_image.h>

namespace Star
{
Texture::Texture(const String& path, uint32 index)
    : m_index(index)
{
    int width, height, nrChannels;
    uint16 type;
    unsigned char* data = stbi_load(path.ToCString(), &width, &height, &nrChannels, 0);
    if (!data) {
        std::cerr << "纹理加载失败！" << std::endl;
        Assert(false);
    }
    GLCall(glGenTextures(1, &m_handle));

    GLCall(glBindTexture(GL_TEXTURE_2D, m_handle));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));// 水平环绕模式
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));// 垂直环绕模式
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));// 缩小过滤
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));// 放大过滤

    switch (nrChannels)
    {
    case 1:
    {
        type = GL_R;
        break;
    }
    case 2:
    {
        type = GL_RG;
        break;
    }
    case 3:
    {
        type = GL_RGB;
        break;
    }
    case 4:
    {
        type = GL_RGBA;
        break;
    }
    default:
    {
        Assert(false);
    }
    }

    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data));
    GLCall(glGenerateMipmap(GL_TEXTURE_2D));
    stbi_image_free(data);
}

Texture::~Texture()
{
    GLCall(glDeleteTextures(1, &m_handle));
}

void Texture::Use() const
{
    GLCall(glActiveTexture(GL_TEXTURE0 + m_index));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_handle));
}
}// namespace Star
