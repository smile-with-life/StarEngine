#include "starpch.h"
#include "Image.h"
#include"Runtime/Core/File/File.h"
#include "stb_image.h"

namespace Star
{
Image::~Image()
{
    Clear();
}

Image::Image(Image&& other) noexcept
    : m_width(other.m_width)
    , m_height(other.m_height)
    , m_size(other.m_size)
    , m_format(other.m_format)
    , m_data(other.m_data)
{
    other.m_width = 0;
    other.m_height = 0;
    other.m_size = 0;
    other.m_format = ImageFormat::None;
    other.m_data = nullptr;
}

Image& Image::operator=(Image&& other) noexcept
{
    if (this == &other) [[unlikely]]
    {
        return *this;
    }

    m_width = other.m_width;
    m_height = other.m_height;
    m_size = other.m_size;
    m_format = other.m_format;
    m_data = other.m_data;

    other.m_width = 0;
    other.m_height = 0;
    other.m_size = 0;
    other.m_format = ImageFormat::None;
    other.m_data = nullptr;

    return *this;
}

Image::Image(const String& path)
{
    Load(path);
}

void Image::Load(const String& path)
{
    Clear();

    int32 width = 0;
    int32 height = 0;
    int32 channels = 0;
    File file(path);

    m_data = stbi_load(path.ToCString(), &width, &height, &channels, 0);
    m_width = width;
    m_height = height;
    m_size = file.Size();

    switch (channels)
    {
    case 1:
    {
        m_format = ImageFormat::R8;
        break;
    }
    case 2:
    {
        m_format = ImageFormat::RG8;
        break;
    }
    case 3:
    {
        m_format = ImageFormat::RGB8;
        break;
    }
    case 4:
    {
        m_format = ImageFormat::RGBA8;
        break;
    }
    default:
    {
        m_format = ImageFormat::None;
        break;
    }
    }// switch 
}

void Image::Clear()
{
    stbi_image_free(m_data);
}

uint32 Image::Width() const
{
    return m_width;
}

uint32 Image::Height() const
{
    return m_height;
}

ImageFormat Image::Format() const
{
    return m_format;
}

uint8* Image::Data()
{
    return m_data;
}
const uint8* Image::Data() const
{
    return m_data;
}
}// namespace Star