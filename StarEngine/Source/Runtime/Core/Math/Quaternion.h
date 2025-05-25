#pragma once
#include"Runtime/Core/Core.h"
#include"Runtime/Core/Concept/Concept.h"
#include "Runtime/Core/Math/Vector3.h"

namespace Star
{
template<Concept::ArithmeticType Type>
class Quaternion
{
public:
    Quaternion()
        : w(Type(1)), x(Type(0)), y(Type(0)), z(Type(0))
    {

    }

    Quaternion(const Quaternion& other) = default;

    Quaternion& operator=(const Quaternion& other) = default;

    Quaternion(Quaternion&& other) noexcept = default;

    Quaternion& operator=(Quaternion&& other) noexcept = default;

    Quaternion(Type w_, Type x_, Type y_, Type z_)
        : w(w_), x(x_), y(y_), z(z_)
    {

    }

    Quaternion(const Radian& angle, const Vector3& axis)
    {

    }

    Quaternion(const float& degree, const Vector3& axis)
    {

    }
public:
    union
    {
        Type data[4];
        struct { Type w, x, y, z; };
    };
};
}// namespace Star