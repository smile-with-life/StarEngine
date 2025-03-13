#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Concept/Concept.h"

#include "Math.h"

namespace Star
{
template<Concept::ArithmeticType Type>
class Vec2
{
public:
    // 默认构造函数
    Vec2() = default;

    // 析构函数
    ~Vec2() = default;

    // 构造函数
    explicit Vec2(Type value)
        : x(value)
        , y(value)
    {

    }

    // 构造函数
    Vec2(Type xValue, Type yValue)
        : x(xValue)
        , y(yValue)
    {

    }

    // 拷贝构造函数
    Vec2(const Vec2& vec2)
        : x(vec2.x)
        , y(vec2.y)
    {

    }

    // 拷贝赋值
    Vec2& operator=(const Vec2& vec2)
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
    Vec2& operator=(std::initializer_list<Type> vecList)
    {
        x = vecList.begin()[0];
        y = vecList.begin()[1];

        return *this;
    }
public:
    // 向量叉积，返回一个标量
    Type Cross(const Vec2& vec2) const
    {
        return x * vec2.y - y * vec2.x;
    }

    // 向量叉积，返回一个标量
    Type operator^(const Vec2& vec2) const
    {
        return Cross(vec2);
    }

    // 向量点积，返回一个值
    Type Dot(const Vec2& vec2) const
    {
        return x * vec2.x + y * vec2.y;
    }

    // 向量点积，返回一个值
    Type operator|(const Vec2& vec2) const
    {
        return Dot(vec2);
    }

    // 向量加法，返回一个新的向量
    Vec2 operator+(const Vec2& vec2) const
    {
        return Vec2(x + vec2.x, y + vec2.y);
    }

    // 向量减法，返回一个新的向量
    Vec2 operator-(const Vec2& vec2) const
    {
        return Vec2(x - vec2.x, y - vec2.y);
    }

    // 向量与另一个向量的分量相乘，返回一个新的向量
    Vec2 operator*(const Vec2& vec2) const
    {
        return Vec2(x * vec2.x, y * vec2.y);
    }

    // 向量与另一个向量的分量相除，返回一个新的向量
    Vec2 operator/(const Vec2& vec2) const
    {
        return Vec2(x / vec2.x, y / vec2.y);
    }

    // 在指定的误差范围内检查两个向量是否相等
    bool isEqual(const Vec2& vec2, Type tolerance = Math::epsilon) const
    {
        return Math::Abs(x - vec2.x) <= tolerance && Math::Abs(y - vec2.y) <= tolerance;
    }

    // 判断两个向量是否相等
    bool operator==(const Vec2& vec2) const
    {
        return x == vec2.x && y == vec2.y;
    }

    // 判断两个向量是否不相等
    bool operator!=(const Vec2& vec2) const
    {
        return x != vec2.x || y != vec2.y;
    }

    // 在指定的误差范围内检查向量中的所有分量是否相等
    bool ComponentsEqual(Type tolerance = Math::epsilon) const
    {
        return Math::Abs(x - y) <= tolerance;
    }

    // 向量取反
    Vec2 operator-() const
    {
        return Vec2(-x, -y);
    }

    // 向量加法，返回它本身
    Vec2& operator+=(const Vec2& vec2)
    {
        x += vec2.x; y += vec2.y;
        return *this;
    }

    // 向量减法，返回它本身
    Vec2& operator-=(const Vec2& vec2)
    {
        x -= vec2.x; y -= vec2.y;
        return *this;
    }

    // 向量与另一个向量的分量相乘，返回它本身
    Vec2& operator*=(const Vec2& vec2)
    {
        x *= vec2.x; y *= vec2.y;
        return *this;
    }

    // 向量与另一个向量的分量相除，返回它本身
    Vec2& operator/=(const Vec2& vec2)
    {
        x /= vec2.x; y /= vec2.y;
        return *this;
    }

    // 向量的每个分量都加上一个标量，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec2 operator+(Scalar scale) const
    {
        return Vec2(x + (Type)scale, y + (Type)scale);
    }

    // 向量的每个分量都减去一个标量，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec2 operator-(Scalar scale) const
    {
        return Vec2(x - (Type)scale, y - (Type)scale);
    }

    // 向量的每个分量都乘以一个值，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec2 operator*(Scalar scale) const
    {
        return Vec2(x * (Type)scale, y * (Type)scale);
    }

    // 获取向量的每个分量除以一个值的结果，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec2 operator/(Scalar scale) const
    {
        const Type invScale = Type(1) / scale;
        return Vec2(x * (Type)invScale, y * (Type)invScale);
    }

    // 向量的每个分量都加上一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec2& operator+=(Scalar scale)
    {
        x += scale; y += scale;
        return *this;
    }

    // 向量的每个分量都减去一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec2& operator-=(Scalar scale)
    {
        x -= scale; y -= scale;
        return *this;
    }

    // 向量的每个分量都乘以一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec2& operator*=(Scalar scale)
    {
        x *= scale; y *= scale;
        return *this;
    }

    // 获取向量的每个分量除以一个值的结果，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec2& operator/=(Scalar scale)
    {
        const Type invScale = (Type)1 / scale;
        x *= invScale; y *= invScale;
        return *this;
    }

    // 获取向量中最大的分量
    Type GetMax() const
    {
        return Math::Max(x, y);
    }

    // 获取向量中绝对值最大的分量
    Type GetAbsMax() const
    {
        return Math::AbsMax(x, y);
    }

    // 获取向量中最小的分量
    Type GetMin() const
    {
        return Math::Min(x, y);
    }

    // 获取向量中绝对值最小的分量
    Type GetAbsMin() const
    {
        return Math::AbsMin(x, y);
    }

    // 获取向量的绝对值,返回一个新的向量
    Vec2 GetAbs() const
    {
        return Vec2(Math::Abs(x), Math::Abs(y));
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

    // 判断是否是近似零向量
    bool IsNearlyZero(Type tolerance = Math::epsilon) const
    {
        return Math::Abs(x) <= tolerance && Math::Abs(y) <= tolerance;
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
    union
    {
        Type data[2];
        struct { Type x, y; };
    };
};

template<Concept::ArithmeticType Type>
class Vec3
{
public:
    // 默认构造函数
    Vec3() = default;

    // 析构函数
    ~Vec3() = default;

    // 构造函数
    explicit Vec3(Type value)
        : x(value)
        , y(value)
        , z(value)
    {

    }

    // 构造函数
    Vec3(Type xValue, Type yValue, Type zValue)
        : x(xValue)
        , y(yValue)
        , z(zValue)
    {

    }
    
    // 拷贝构造函数
    Vec3(const Vec3& vec3)
        : x(vec3.x)
        , y(vec3.y)
        , z(vec3.z)
    {

    }

    // 拷贝赋值
    Vec3& operator=(const Vec3& vec3)
    {
        if (&vec3 == this) [[unlikely]]
        {
            return *this;
        }

        x = vec3.x;
        y = vec3.y;
        z = vec3.z;

        return *this;
    }

    // 列表构造函数
    Vec3& operator=(std::initializer_list<Type> vecList)
    {
        x = vecList.begin()[0];
        y = vecList.begin()[1];
        z = vecList.begin()[2];

        return *this;
    }
public:
    // 向量叉积，返回一个新的向量
    Vec3 Cross(const Vec3& vec3) const
    { 
        return Vec3(
                y * vec3.z - z * vec3.y,
                z * vec3.x - x * vec3.z,
                x * vec3.y - y * vec3.x
            );
        
    }

    // 向量叉积，返回一个新的向量
    Vec3 operator^(const Vec3& vec3) const
    {
        return Cross(vec3);
    }   

    // 向量点积，返回一个值
    Type Dot(const Vec3& vec3) const
    {
        return x * vec3.x + y * vec3.y + z * vec3.z;
    }

    // 向量点积，返回一个值
    Type operator|(const Vec3& vec3) const
    {
        return Dot(vec3);
    }

    // 向量加法，返回一个新的向量
    Vec3 operator+(const Vec3& vec3) const
    {
        return Vec3(x + vec3.x, y + vec3.y, z + vec3.z);
    }

    // 向量减法，返回一个新的向量
    Vec3 operator-(const Vec3& vec3) const
    {
        return Vec3(x - vec3.x, y - vec3.y, z - vec3.z);
    }

    // 向量与另一个向量的分量相乘，返回一个新的向量
    Vec3 operator*(const Vec3& vec3) const
    {
        return Vec3(x * vec3.x, y * vec3.y, z * vec3.z);
    }

    // 向量与另一个向量的分量相除，返回一个新的向量
    Vec3 operator/(const Vec3& vec3) const
    {
        return Vec3(x / vec3.x, y / vec3.y, z / vec3.z);
    }

    // 在指定的误差范围内检查两个向量是否相等
    bool isEqual(const Vec3& vec3, Type tolerance = Math::epsilon) const
    {
        return Math::Abs(x - vec3.x) <= tolerance && 
               Math::Abs(y - vec3.y) <= tolerance &&
               Math::Abs(z - vec3.z) <= tolerance;
    }

    // 判断两个向量是否相等
    bool operator==(const Vec3& vec3) const
    {
        return x == vec3.x && y == vec3.y && z == vec3.z;
    }

    // 判断两个向量是否不相等
    bool operator!=(const Vec3& vec3) const
    {
        return x != vec3.x || y != vec3.y || z != vec3.z;
    }

    // 在指定的误差范围内检查向量中的所有分量是否相等
    bool ComponentsEqual(Type tolerance = Math::epsilon) const
    {
        return Math::Abs(x - y) <= tolerance &&
               Math::Abs(x - z) <= tolerance &&
               Math::Abs(y - z) <= tolerance;
    }

    // 向量取反
    Vec3 operator-() const
    {
        return Vec3(-x, -y, -z);
    }

    // 向量加法，返回它本身
    Vec3& operator+=(const Vec3& vec3)
    {
        x += vec3.x; y += vec3.y; z += vec3.z;
        return *this;
    }

    // 向量减法，返回它本身
    Vec3& operator-=(const Vec3& vec3)
    {
        x -= vec3.x; y -= vec3.y; z -= vec3.z;
        return *this;
    }

    // 向量与另一个向量的分量相乘，返回它本身
    Vec3& operator*=(const Vec3& vec3)
    {
        x *= vec3.x; y *= vec3.y; z *= vec3.z;
        return *this;
    }

    // 向量与另一个向量的分量相除，返回它本身
    Vec3& operator/=(const Vec3& vec3)
    {
        x /= vec3.x; y /= vec3.y; z /= vec3.z;
        return *this;
    }

    // 向量的每个分量都加上一个标量，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec3 operator+(Scalar scale) const
    {
        return Vec3(x + (Type)scale, y + (Type)scale, z + (Type)scale);
    }

    // 向量的每个分量都减去一个标量，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec3 operator-(Scalar scale) const
    {
        return Vec3(x - (Type)scale, y - (Type)scale, z - (Type)scale);
    }

    // 向量的每个分量都乘以一个值，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec3 operator*(Scalar scale) const
    {
        return Vec3(x * (Type)scale, y * (Type)scale, z * (Type)scale);
    }

    // 获取向量的每个分量除以一个值的结果，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec3 operator/(Scalar scale) const
    {
        const Type invScale = Type(1) / scale;
        return Vec3(x * (Type)invScale, y * (Type)invScale, z * (Type)invScale);
    }

    // 向量的每个分量都加上一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec3& operator+=(Scalar scale)
    {
        x += scale; y += scale; z += scale;
        return *this;
    }

    // 向量的每个分量都减去一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec3& operator-=(Scalar scale)
    {
        x -= scale; y -= scale; z -= scale;
        return *this;
    }

    // 向量的每个分量都乘以一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec3& operator*=(Scalar scale)
    {
        x *= scale; y *= scale; z *= scale;
        return *this;
    }

    // 获取向量的每个分量除以一个值的结果，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec3& operator/=(Scalar scale)
    {
        const Type invScale = (Type)1 / scale;
        x *= invScale; y *= invScale; z *= invScale;
        return *this;
    }

    // 获取向量中最大的分量
    Type GetMax() const
    {
        return Math::Max(Math::Max(x, y), z);
    }

    // 获取向量中绝对值最大的分量
    Type GetAbsMax() const
    {
        return Math::AbsMax(Math::AbsMax(x, y), z);
    }

    // 获取向量中最小的分量
    Type GetMin() const
    {
        return Math::Min(Math::Min(x, y), z);
    }

    // 获取向量中绝对值最小的分量
    Type GetAbsMin() const
    {
        return Math::AbsMin(Math::AbsMin(x, y), z);
    }

    // 获取向量的绝对值,返回一个新的向量
    Vec3 GetAbs() const
    {
        return Vec3(Math::Abs(x), Math::Abs(y), Math::Abs(z));
    }
    
    // 获取向量的模长
    Type Length() const
    {
        return Math::Sqrt(x * x + y * y + z * z);
    }

    // 获取向量的模长的平方
    Type SquaredLength() const
    {
        return x * x + y * y + z * z;
    }

    // 归一化
    bool Normalize(Type tolerance = Math::epsilon)
    {
        const Type square = x * x + y * y + z * z;
        if (square > tolerance)
        {
            const Type scale = Math::InvSqrt(square);
            x *= scale;
            y *= scale;
            z *= scale;
            return true;
        }
        return false;
    }

    // 判断是否是近似零向量
    bool IsNearlyZero(Type tolerance = Math::epsilon) const
    {
        return Math::Abs(x) <= tolerance && 
               Math::Abs(y) <= tolerance && 
               Math::Abs(z) <= tolerance;
    }

    // 判断是否是零向量
    bool IsZero() const
    {
        return x == 0.0f && y == 0.0f && z == 0.0f;
    }

    // 判断是否是单位向量
    bool IsUnit() const
    {
        return Math::Abs(1.0f - SquaredLength()) < 0.01f;
    }
public:
    union 
    {
        Type data[3];
        struct { Type x, y, z; };
    };
};

template<Concept::ArithmeticType Type>
class Vec4
{
public:
    // 默认构造函数
    Vec4() = default;

    // 析构函数
    ~Vec4() = default;

    // 构造函数
    explicit Vec4(Type value)
        : x(value)
        , y(value)
        , z(value)
        , w(value)
    {

    }

    // 构造函数
    Vec4(const Vec3<Type>& vec3, Type wValue = 1.0f)
        : x(vec3.x)
        , y(vec3.y)
        , z(vec3.z)
        , w(wValue)
    {

    }

    // 构造函数
    Vec4(Type xValue, Type yValue, Type zValue, Type wValue)
        : x(xValue)
        , y(yValue)
        , z(zValue)
        , w(wValue)
    {

    }

    // 拷贝构造函数
    Vec4(const Vec4& vec4)
        : x(vec4.x)
        , y(vec4.y)
        , z(vec4.z)
        , w(vec4.w)
    {

    }

    // 拷贝赋值
    Vec4& operator=(const Vec4& vec4)
    {
        if (&vec4 == this) [[unlikely]]
        {
            return *this;
        }

        x = vec4.x;
        y = vec4.y;
        z = vec4.z;
        w = vec4.w;

        return *this;
    }

    // 列表构造函数
    Vec4& operator=(std::initializer_list<Type> vecList)
    {
        x = vecList.begin()[0];
        y = vecList.begin()[1];
        z = vecList.begin()[2];
        w = vecList.begin()[3];

        return *this;
    }
public:
    // 向量加法，返回一个新的向量
    Vec4 operator+(const Vec4& vec4) const
    {
        return Vec4(x + vec4.x, y + vec4.y, z + vec4.z, w + vec4.w);
    }

    // 向量减法，返回一个新的向量
    Vec4 operator-(const Vec4& vec4) const
    {
        return Vec4(x - vec4.x, y - vec4.y, z - vec4.z, w - vec4.w);
    }

    // 向量与另一个向量的分量相乘，返回一个新的向量
    Vec4 operator*(const Vec4& vec4) const
    {
        return Vec4(x * vec4.x, y * vec4.y, z * vec4.z, w * vec4.w);
    }

    // 向量与另一个向量的分量相除，返回一个新的向量
    Vec4 operator/(const Vec4& vec4) const
    {
        return Vec4(x / vec4.x, y / vec4.y, z / vec4.z, w / vec4.w);
    }

    // 在指定的误差范围内检查两个向量是否相等
    bool isEqual(const Vec4& vec4, Type tolerance = Math::epsilon) const
    {
        return Math::Abs(x - vec4.x) <= tolerance &&
            Math::Abs(y - vec4.y) <= tolerance &&
            Math::Abs(z - vec4.z) <= tolerance &&
            Math::Abs(w - vec4.w) <= tolerance;
    }

    // 判断两个向量是否相等
    bool operator==(const Vec4& vec4) const
    {
        return x == vec4.x && y == vec4.y && z == vec4.z && w == vec4.w;
    }

    // 判断两个向量是否不相等
    bool operator!=(const Vec4& vec4) const
    {
        return x != vec4.x || y != vec4.y || z != vec4.z || w != vec4.w;
    }

    // 向量取反
    Vec4 operator-() const
    {
        return Vec4(-x, -y, -z, -w);
    }

    // 向量加法，返回它本身
    Vec4& operator+=(const Vec4& vec4)
    {
        x += vec4.x; y += vec4.y; z += vec4.z; w += vec4.w;
        return *this;
    }

    // 向量减法，返回它本身
    Vec4& operator-=(const Vec4& vec4)
    {
        x -= vec4.x; y -= vec4.y; z -= vec4.z; w -= vec4.w;
        return *this;
    }

    // 向量与另一个向量的分量相乘，返回它本身
    Vec4& operator*=(const Vec4& vec4)
    {
        x *= vec4.x; y *= vec4.y; z *= vec4.z; w *= vec4.w;
        return *this;
    }

    // 向量与另一个向量的分量相除，返回它本身
    Vec4& operator/=(const Vec4& vec4)
    {
        x /= vec4.x; y /= vec4.y; z /= vec4.z; w /= vec4.w;
        return *this;
    }

    // 向量的每个分量都加上一个标量，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec4 operator+(Scalar scale) const
    {
        return Vec4(x + (Type)scale, y + (Type)scale, z + (Type)scale, w + (Type)scale);
    }

    // 向量的每个分量都减去一个标量，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec4 operator-(Scalar scale) const
    {
        return Vec4(x - (Type)scale, y - (Type)scale, z - (Type)scale, w - (Type)scale);
    }

    // 向量的每个分量都乘以一个值，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec4 operator*(Scalar scale) const
    {
        return Vec4(x * (Type)scale, y * (Type)scale, z * (Type)scale, w * (Type)scale);
    }

    // 获取向量的每个分量除以一个值的结果，返回一个新的向量
    template<Concept::ArithmeticType Scalar>
    Vec4 operator/(Scalar scale) const
    {
        const Type invScale = Type(1) / scale;
        return Vec4(x * (Type)invScale, y * (Type)invScale, z * (Type)invScale, w * (Type)invScale);
    }

    // 向量的每个分量都加上一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec4& operator+=(Scalar scale)
    {
        x += scale; y += scale; z += scale; w += scale;
        return *this;
    }

    // 向量的每个分量都减去一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec4& operator-=(Scalar scale)
    {
        x -= scale; y -= scale; z -= scale; w -= scale;
        return *this;
    }

    // 向量的每个分量都乘以一个值，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec3<Type>& operator*=(Scalar scale)
    {
        x *= scale; y *= scale; z *= scale; w *= scale;
        return *this;
    }

    // 获取向量的每个分量除以一个值的结果，返回它本身
    template<Concept::ArithmeticType Scalar>
    Vec3<Type>& operator/=(Scalar scale)
    {
        const Type invScale = (Type)1 / scale;
        x *= invScale; y *= invScale; z *= invScale; w *= invScale;
        return *this;
    }
public:
    union
    {
        Type data[4];
        struct { Type x, y, z, w; };
    };
};
}//namespace Star