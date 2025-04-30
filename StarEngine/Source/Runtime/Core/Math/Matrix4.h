#pragma once
#include"Runtime/Core/Core.h"
#include"Runtime/Core/Concept/Concept.h"

#include <initializer_list>
#include "Math.h"
#include "Vector4.h"

namespace Star
{
template<Concept::ArithmeticType Type>
class Matrix4
{
public:
    Matrix4();
    ~Matrix4();
    Matrix4(const Matrix4& other);
    Matrix4& operator=(const Matrix4& other);
    Matrix4(Matrix4&& other);
    Matrix4& operator=(Matrix4&& other);
public:
    Type* operator[](int32 row)
    {
        Assert(row < 4);
        return (Type*)data[row];
    }

    const Type* operator[](int32 row) const
    {
        Assert(row < 4);
        return (Type*)data[row];
    }

    friend Matrix4 operator+(const Matrix4& left, const Matrix4& right)
    {
        Matrix4 result;
        for (int32 row = 0; row < 4; row++)
        {
            for (int32 column = 0; column < 4; column++)
            {
                result.data[row][column] = left.data[row][column] + right.data[row][column];
            }
        }
        return result;
    }

    friend Matrix4 operator-(const Matrix4& left, const Matrix4& right)
    {
        Matrix4 result;
        for (int32 row = 0; row < 4; row++)
        {
            for (int32 column = 0; column < 4; column++)
            {
                result.data[row][column] = left.data[row][column] - right.data[row][column];
            }
        }
        return result;
    }

    friend Matrix4 operator*(const Matrix4& left, const Matrix4& right)
    {
        Matrix4 result;
        for (int32 row = 0; row < 4; row++)
        {
            for (int32 column = 0; column < 4; column++)
            {
                result.data[row][column] = left.data[row][0] * right.data[0][column] + left.data[row][1] * right.data[1][column] + left.data[row][2] * right.data[2][column] + left.data[row][3] * right.data[3][column];
            }
        }
        return result;
    }

    friend Matrix4 operator*(const Matrix4& mat4, Type scalar)
    {
        Matrix4 result;
        for (int32 row = 0; row < 4; row++)
        {
            for (int32 column = 0; column < 4; column++)
            {
                result.data[row][column] = scalar * mat4.data[row][column];
            }
        }
        return result;
    }

    friend Matrix4 operator*(Type scalar, const Matrix4& mat4)
    {
        Matrix4 result;
        for (int32 row = 0; row < 4; row++)
        {
            for (int32 column = 0; column < 4; column++)
            {
                result.data[row][column] = scalar * mat4.data[row][column];
            }
        }
        return result;
    }

    friend Vector4<Type> operator*(const Matrix4& mat4, const Vector4<Type>& vec4)
    {
        Vector4<Type> result;
        for (size_t row = 0; row < 4; row++)
        {
            result.data[row] = mat4.data[row][0] * vec4.x + mat4.data[row][1] * vec4.y + mat4.data[row][2] * vec4.z + +mat4.data[row][3] * vec4.w;
        }
        return result;
    }

    friend Vector4<Type> operator*(const Vector4<Type>& vec4, const Matrix4& mat4)
    {
        Vector4<Type> result;
        for (size_t row = 0; row < 4; row++)
        {
            result.data[row] = vec4.x * mat4.data[0][row] + vec4.y * mat4.data[1][row] + vec4.z * mat4.data[2][row] + vec4.w * mat4.data[3][row];
        }
        return result;
    }
public:
    union
    {
        Type data[4][4];
    };
};
}// namespace Star