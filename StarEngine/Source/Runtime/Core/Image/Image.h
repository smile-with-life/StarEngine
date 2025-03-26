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
struct Image
{
    uint32 width; // 图像的宽度
    uint32 height;// 图像的高度
    uint32 pixelBit;// 像素的位大小
    uint32 colorDepth;// 颜色深度
    uint32 pitch;// 每行像素的字节数
    uint32 size;// 图像数据大小
    bool isCompressed;// 是否为压缩数据
    bool isFloat;// 数据类型是否为float
    bool isSigned;// 数据类型是否为有符号数
    uint8* data;// 数据
    CompressedFormat compressedFormat;// 压缩格式
    PixelFormat pixelFormat;// 像素格式
};
}// namespace Star