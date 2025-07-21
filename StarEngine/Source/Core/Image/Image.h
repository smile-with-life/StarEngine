#pragma once
#include "Core/Core.h"
#include "Core/String/String.h"


namespace Star
{
// 图像格式
enum class ImageFormat: uint16
{
    None,
    R8,
    RG8,
    RGB8,
    RGBA8,
};

// 图像
class Image 
{
public:
    Image() = default;

    ~Image();

    Image(const Image& other) = delete;

    Image& operator=(const Image& other) = delete;

    Image(Image&& other) noexcept;

    Image& operator=(Image&& other) noexcept;

    Image(const String& path);
public:
    void Load(const String& path);

    void Clear();

    uint32 Width() const;

    uint32 Height() const;

    ImageFormat Format() const;

    uint8* Data();

    const uint8* Data() const;
private:
    // 图像的宽度，以像素为单位
    uint32 m_width = 0;

    // 图像的高度，以像素为单位
    uint32 m_height = 0;

    // 图像大小
    uint32 m_size = 0;
    
    // 图像的格式
    ImageFormat m_format = ImageFormat::None;

    // 数据
    uint8* m_data = nullptr;
};
}// namespace Star