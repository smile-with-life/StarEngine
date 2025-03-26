#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
// 压缩格式
enum class CompressedFormat: uint16
{
    None,
    DXT1,
    DXT2,
    DXT3,
    DXT4,
    DXT5,
    DXT10,
    BC1,
    BC1A,
    BC2,
    BC3,
    BC4,
    BC5,
    BC6H,
    BC7,
    PVRTC,
    ETC,
    ASTC_4x4,
    ASTC_5x4,
    ASTC_5x5,
    ASTC_6x5,
    ASTC_6x6,
    ASTC_8x5,
    ASTC_8x6,
    ASTC_8x8,
    ASTC_10x5,
    ASTC_10x6,
    ASTC_10x8,
    ASTC_10x10,
    ASTC_12x10,
    ASTC_12x12,
    ASTC_3x3x3,
    ASTC_4x3x3,
    ASTC_4x4x3,
    ASTC_4x4x4,
    ASTC_5x4x4,
    ASTC_5x5x4,
    ASTC_5x5x5,
    ASTC_6x5x5,
    ASTC_6x6x5,
    ASTC_6x6x6,
};

// 像素格式
enum class PixelFormat: uint16
{
    None,
    R8,
    RG8,
    RGB8,
    RGBA8,
    R16,
    RG16,
    RGB16,
    RGBA16,
    R32,
    RG32,
    RGB32,
    RGBA32,
    R10G10B10A2,
    R5G6B5,
    D24R8,
    D32
};

// 图像
class Image
{
public:
    Image() = default;

    ~Image();

    Image(const Image& other);

    Image& operator=(const Image& other);

    Image(Image&& other);

    Image& operator=(Image&& other);

    Image(const String& path);
public:

private:
    // 图片的宽度，以像素为单位
    uint32 m_width = 0;

    // 图片的高度，以像素为单位
    uint32 m_height = 0;

    // 像素的位大小
    uint32 m_pixelBit = 0;

    // 颜色深度
    uint32 m_colorDepth = 0;

    // 每行的字节数
    uint32 m_pitch;

    // 图片大小
    uint32 m_size = 0;

    // 是否为压缩数据
    bool m_isCompressed = false;

    // 数据类型是否为float
    bool m_isFloat = false;

    // 数据类型是否为有符号数
    bool m_isSigned = false;

    // 数据
    uint8* m_data = nullptr;

    // 压缩格式
    CompressedFormat m_compressedFormat = CompressedFormat::None;

    // 像素格式
    PixelFormat m_pixelFormat = PixelFormat::None;
};
}// namespace Star