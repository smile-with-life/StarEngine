#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
// 视口
class Viewport
{
public:
	Viewport() = default;

	~Viewport() = default;

	Viewport(const Viewport& other) = default;

	Viewport& operator=(const Viewport& other) = default;

	Viewport(Viewport&& other) = default;

	Viewport& operator=(Viewport&& other) = default;

	Viewport(float x, float y, float width, float height);

	Viewport(float x, float y, float width, float height, float depthMin, float depthMax);
public:
	friend bool operator==(const Viewport& left, const Viewport& right);

	friend bool operator!=(const Viewport& left, const Viewport& right);
public:
	// 视口起始位置 X 坐标
	float X = 0.0f;

	// 视口起始位置 Y 坐标
	float Y = 0.0f;

	// 视口的宽度
	float Width = 0.0f;

	// 视口的高度
	float Height = 0.0f;

	// 视口的近裁剪面深度
	float DepthMin = 0.0f;

	// 视口的远裁剪面深度
	float DepthMax = 1.0f;
};
}// namespace Star