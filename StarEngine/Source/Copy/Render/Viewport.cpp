#include "starpch.h"
#include "Viewport.h"

namespace Star
{
Viewport::Viewport(float x, float y, float width, float height)
    : X(x), Y(y), Width(width), Height(height)
{

}

Viewport::Viewport(float x, float y, float width, float height, float depthMin, float depthMax)
    : X(x), Y(y), Width(width), Height(height), DepthMin(depthMin), DepthMax(depthMax)
{

}

bool operator==(const Viewport& left, const Viewport& right)
{
    return
        left.X == right.X && left.Y == right.Y &&
        left.Width == right.Width && left.Height == right.Height &&
        left.DepthMin == right.DepthMin && left.DepthMax == right.DepthMax;
}

bool operator!=(const Viewport& left, const Viewport& right)
{
    return !(left == right);
}
}// namespace Star