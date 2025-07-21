#include "starpch.h"
#include "SwapChain.h"

namespace Star
{
SwapChain::SwapChain(int32 width, int32 height, PixelFormat pixelFormat)
    :m_width(width), m_height(height), m_pixelFormat(pixelFormat)
{

}

int32 SwapChain::GetWidth() const
{
    return m_width;
}

int32 SwapChain::GetHeight() const
{
    return m_height;
}

PixelFormat SwapChain::GetPixelFormat() const
{
    return m_pixelFormat;
}
}// namespace Star