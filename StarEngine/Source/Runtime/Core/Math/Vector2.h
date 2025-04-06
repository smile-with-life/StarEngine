#pragma once
#include"Runtime/Core/Core.h"
#include"Runtime/Core/Concept/Concept.h"

#include <initializer_list>
#include "Math.h"


namespace Star
{
// 二维向量
template<Concept::ArithmeticType Type>
class Vector2
{
public:
    // 默认构造函数
    Vector2()
        : x(0), y(0)
    {

    }

    // 析构函数
    ~Vector2() = default;

    // 拷贝构造函数
    Vector2(const Vector2& vec2)
        : x(vec2.x), y(vec2.y)
    {

    }

    // 拷贝赋值
    Vector2& operator=(const Vector2& vec2)
    {
        if (&vec2 == this) [[unlikely]]
        {
            return *this;
        }

        x = vec2.x;
        y = vec2.y;

        return *this;
    }

    // 列表构造函数
    Vector2& operator=(std::initializer_list<Type> vecList)
    {
        x = vecList.begin()[0];
        y = vecList.begin()[1];

        return *this;
    }

    // 构造函数
    explicit Vector2(Type value)
        : x(value), y(value)
    {

    }

    // 构造函数
    Vector2(Type xValue, Type yValue)
        : x(xValue), y(yValue)
    {

    }
public:
    // 向量叉积，返回一个标量
    Type Cross(const Vector2& vec2) const
    {
        return x * vec2.y - y * vec2.x;
    }

    // 向量点积，返回一个值
    Type Dot(const Vector2& vec2) const
    {
        return x * vec2.x + y * vec2.y;
    }

    // 获取向量的模长
    Type Length() const
    {
        return Math::Sqrt(x * x + y * y);
    }

    // 获取向量的模长的平方
    Type SquaredLength() const
    {
        return x * x + y * y;
    }

    // 两个向量的距离
    Type Distance(const Vector2& vec2) const 
    { 
        return (*this - vec2).Length();
    }

    // 归一化
    bool Normalize(Type tolerance = Math::epsilon)
    {
        const Type square = x * x + y * y;
        if (square > tolerance)
        {
            const Type scale = Math::InvSqrt(square);
            x *= scale; y *= scale;
            return true;
        }
        return false;
    }

    // 判断是否是零向量
    bool IsZero() const
    {
        return x == 0.0f && y == 0.0f;
    }

    // 判断是否是单位向量
    bool IsUnit() const
    {
        return Math::Abs(1.0f - SquaredLength()) < 0.01f;
    }
public:
    // 向量取反
    Vector2 operator-() const
    {
        return Vector2(-x, -y);
    }

    // 判断两个向量是否相等
    bool operator==(const Vector2& vec2) const
    {
        return x == vec2.x && y == vec2.y;
    }

    // 判断两个向量是否不相等
    bool operator!=(const Vector2& vec2) const
    {
        return x != vec2.x || y != vec2.y;
    }

    // 两个向量相加，返回一个新的向量
    Vector2 operator+(const Vector2& vec2) const
    {
        return Vector2(x + vec2.x, y + vec2.y);
    }

    // 两个向量相加，返回它本身
    Vector2& operator+=(const Vector2& vec2)
    {
        x += vec2.x; y += vec2.y;
        return *this;
    }

    // 向量加上一个标量，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vector2 operator+(Scalar scale) const
    {
        return Vec2(x + (Type)scale, y + (Type)scale);
    }

    // 向量加上一个标量，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vector2& operator+=(Scalar scale)
    {
        x += scale; y += scale;
        return *this;
    }

    // 两个向量相减，返回一个新的向量
    Vector2 operator-(const Vector2& vec2) const
    {
        return Vec2(x - vec2.x, y - vec2.y);
    }

    // 两个向量相减，返回它本身
    Vector2& operator-=(const Vector2& vec2)
    {
        x -= vec2.x; y -= vec2.y;
        return *this;
    }

    // 向量减去一个标量，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vector2 operator-(Scalar scale) const
    {
        return Vec2(x - (Type)scale, y - (Type)scale);
    }

    // 向量减去一个标量，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vector2& operator-=(Scalar scale)
    {
        x -= scale; y -= scale;
        return *this;
    }

    // 两个向量的分量相乘，返回一个新的向量
    Vector2 operator*(const Vector2& vec2) const
    {
        return Vec2(x * vec2.x, y * vec2.y);
    }

    // 两个向量的分量相乘，返回它本身
    Vector2& operator*=(const Vector2& vec2)
    {
        x *= vec2.x; y *= vec2.y;
        return *this;
    }

    // 向量的分量都乘以一个值，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vector2 operator*(Scalar scale) const
    {
        return Vec2(x * (Type)scale, y * (Type)scale);
    }

    // 向量的分量都乘以一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vector2& operator*=(Scalar scale)
    {
        x *= scale; y *= scale;
        return *this;
    }

    // 两个向量的分量相除，返回一个新的向量
    Vector2 operator/(const Vector2& vec2) const
    {
        return Vec2(x / vec2.x, y / vec2.y);
    }

    // 两个向量的分量相除，返回它本身
    Vector2& operator/=(const Vector2& vec2)
    {
        x /= vec2.x; y /= vec2.y;
        return *this;
    }

    // 向量的分量都除以一个值，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vector2 operator/(Scalar scale) const
    {
        const Type invScale = Type(1) / scale;
        return Vector2(x * (Type)invScale, y * (Type)invScale);
    }

    // 向量的分量都除以一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vector2& operator/=(Scalar scale)
    {
        const Type invScale = (Type)1 / scale;
        x *= invScale; y *= invScale;
        return *this;
    }
public:
    union
    {
        Type data[2];
        struct { Type x, y; };
    };
};
}// namespace Star