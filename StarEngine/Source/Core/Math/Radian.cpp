#include "starpch.h"
#include "Radian.h"

#include "Core/Math/Math.h"

namespace Star
{
Radian::Radian(const Radian& other)
    : m_rad(other.m_rad)
{
    
}

Radian& Radian::operator=(const Radian& other)
{
    if (this == &other) [[unlikely]]
    {
        return *this;
    }
    m_rad = other.m_rad;
    return *this;
}

Radian::Radian(Radian&& other) noexcept
    : m_rad(other.m_rad)
{
    other.m_rad = 0;
}

Radian& Radian::operator=(Radian&& other) noexcept
{
    if (this == &other) [[unlikely]]
    {
        return *this;
    }
    m_rad = other.m_rad;
    other.m_rad = 0;
    return *this;
}

Radian::Radian(float degree)
{
    m_rad = Math::DegToRad(degree);
}

Radian& Radian::operator=(float degree)
{
    m_rad = Math::DegToRad(degree);
    return *this;
}

Radian Radian::operator-() const
{
    Radian result;
    result.m_rad = -m_rad;
    return result;
}

Radian Radian::operator+() const
{
    Radian result;
    result.m_rad = m_rad;
    return result;
}

bool Radian::operator==(const Radian& other) const
{
    return m_rad == other.m_rad;
}

bool Radian::operator!=(const Radian& other) const
{
    return m_rad != other.m_rad;
}

bool Radian::operator>(const Radian& other) const
{
    return m_rad > other.m_rad;
}

bool Radian::operator>=(const Radian& other) const
{
    return m_rad >= other.m_rad;
}

bool Radian::operator<(const Radian& other) const
{
    return m_rad < other.m_rad;
}

bool Radian::operator<=(const Radian& other) const
{
    return m_rad <= other.m_rad;
}

Radian Radian::operator+(const Radian& other) const
{
    Radian result;
    result.m_rad = m_rad + other.m_rad;
    return result;
}

Radian& Radian::operator+=(const Radian& other)
{
    m_rad += other.m_rad;
    return *this;
}

Radian Radian::operator-(const Radian& other) const
{
    Radian result;
    result.m_rad = m_rad - other.m_rad;
    return result;
}

Radian& Radian::operator-=(const Radian& other)
{
    m_rad -= other.m_rad;
    return *this;
}

Radian Radian::operator*(const Radian& other) const
{
    Radian result;
    result.m_rad = m_rad * other.m_rad;
    return result;
}

Radian& Radian::operator*=(const Radian& other)
{
    m_rad *= other.m_rad;
    return *this;
}

Radian Radian::operator/(const Radian& other) const
{
    Radian result;
    result.m_rad = m_rad / other.m_rad;
    return result;
}

Radian& Radian::operator/=(const Radian& other)
{
    m_rad /= other.m_rad;
    return *this;
}
}// namespace Star