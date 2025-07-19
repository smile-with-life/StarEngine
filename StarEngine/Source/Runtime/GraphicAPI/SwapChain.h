#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{

enum class PixelFormat
{
	// Undefined
	None,
	// R
	R8_Unorm,
	R16_Uint,
	R16_Float,
	R32_Uint,
	R32_Float,
	// RG
	R8G8_Unorm,
	R16G16_Float,
	R32G32_Float,
	// RGB
	R11G11B10_Float,
	R32G32B32_Float,
	// RGBA
	R8G8B8A8_Unorm,
	R10G10B10A2_Unorm,
	R16G16B16A16_Snorm,
	R16G16B16A16_Float,
	R32G32B32A32_Float,
	// DEPTH
	D32_Float,
	D32_Float_S8X24_Uint
};
// 交换链
class SwapChain
{
public:
	SwapChain() = default;

	virtual ~SwapChain() = default;

	SwapChain(const SwapChain& other) = default;

	SwapChain& operator=(const SwapChain& other) = default;

	SwapChain(SwapChain&& other) = default;

	SwapChain& operator=(SwapChain&& other) = default;

	SwapChain(int32 width, int32 height, PixelFormat pixelFormat);
public:
	virtual bool Present() = 0;

	virtual bool Resize(int32 width, int32 height) = 0;

	int32 GetWidth() const;

	int32 GetHeight() const;

	PixelFormat GetPixelFormat() const;
protected:
	int32 m_width;

	int32 m_height;

	PixelFormat m_pixelFormat;
};
}// namespace Star