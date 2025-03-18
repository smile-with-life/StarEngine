#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Container/Array.h"

namespace Star
{
// 压缩格式
enum class CompressedFormat
{
    None,
};

// 像素格式
enum class PixelFormat
{
    Unknown,
};

// 分级纹理
struct Mipmap
{
    uint32 Width;
    uint32 Height;
    uint32 Pitch;
    uint32 Offset;
    uint32 Size;
};


// 图像
class Image
{
private:
    uint32 m_width; // 图像的宽度
    uint32 m_height;// 图像的高度
    uint32 m_pixelBit;//像素的位数
    uint32 m_colorDepth;// 颜色深度
    uint32 m_pitch;// 每行像素的字节数
    uint32 m_size;// 图像数据大小
    bool m_isCompressed;// 是否为压缩数据
    bool m_isFloat;// 数据类型是否为float
    bool m_isSigned;// 数据类型是否为有符号数
    uint8* m_data;// 数据
    CompressedFormat m_compressedFormat;// 压缩格式
    PixelFormat m_pixelFormat;// 像素格式
};
}// namespace Star