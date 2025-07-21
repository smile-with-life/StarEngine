#pragma once
#include"Core/Core.h"
#include"Core/Concept/Concept.h"

#include <initializer_list>
#include "Math.h"
#include "Vector3.h"

namespace Star
{
template<Concept::ArithmeticType Type>
class Matrix3
{
public:
    Matrix3()
    {
        data[0][0] = 1; data[0][1] = 0; data[0][2] = 0;
        data[1][0] = 0; data[1][1] = 1; data[1][2] = 0;
        data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
    }

    ~Matrix3() = default;

    Matrix3(const Matrix3& other)
    {
        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                data[row][cloumn] = other.data[row][cloumn];
            }
        }
    }

    Matrix3& operator=(const Matrix3& other)
    {
        if (*this == other) [[unlikely]]
        {
            return *this;
        }

        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                data[row][cloumn] = other.data[row][cloumn];
            }
        }
        return *this;
    }

    Matrix3(Matrix3&& other) noexcept
    {
        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                data[row][cloumn] = other.data[row][cloumn];
                other.data[row][cloumn] = 0;
            }
        }
    }

    Matrix3& operator=(Matrix3&& other) noexcept
    {
        if (*this == other) [[unlikely]]
        {
            return *this;
        }

        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                data[row][cloumn] = other.data[row][cloumn];
                other.data[row][cloumn] = 0;
            }
        }
        return *this;
    }

    explicit Matrix3(Type arr[3][3])
    {
        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                data[row][cloumn] = arr[row][cloumn];   
            }
        }
    }

    explicit Matrix3(Type(&arr)[9])
    {
        for (int32 row = 0; row < 3; row++) 
        {
            for (int32 column = 0; column < 3; column++) 
            {
                data[row][column] = arr[row * 3 + column];
            }
        }
    }

    Matrix3(const Vector3& row0, const Vector3& row1, const Vector3& row2)
    {
        data[0][0] = row0.x; data[0][1] = row0.y; data[0][2] = row0.z;
        data[1][0] = row1.x; data[1][1] = row1.y; data[1][2] = row1.z;
        data[2][0] = row2.x; data[2][1] = row2.y; data[2][2] = row2.z;
    }
public:
    Type* operator[](int32 row)
    { 
        Assert(row < 3);
        return (Type*)data[row];
    }

    const Type* operator[](int32 row) const
    {
        Assert(row < 3);
        return (Type*)data[row];
    }

    friend Matrix3 operator+(const Matrix3& left, const Matrix3& right)
    {
        Matrix3 result;
        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                result.data[row][column] = left.data[row][column] + right.data[row][column];
            }
        }
        return result;
    }

    friend Matrix3 operator-(const Matrix3& left, const Matrix3& right)
    {
        Matrix3 result;
        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                result.data[row][column] = left.data[row][column] - right.data[row][column];
            }
        }
        return result;
    }

    friend Matrix3 operator*(const Matrix3& left, const Matrix3& right)
    {
        Matrix3 result;
        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                result.data[row][column] = left.data[row][0] * right.data[0][column] + left.data[row][1] * right.data[1][column] + left.data[row][2] * right.data[2][column];
            }
        }
        return result;
    }

    friend Matrix3 operator*(const Matrix3& mat3, Type scalar)
    {
        Matrix3 result;
        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                result.data[row][column] = scalar * mat3.data[row][column];
            }
        }
        return result;
    }

    friend Matrix3 operator*(Type scalar, const Matrix3& mat3)
    {
        Matrix3 result;
        for (int32 row = 0; row < 3; row++)
        {
            for (int32 column = 0; column < 3; column++)
            {
                result.data[row][column] = scalar * mat3.data[row][column];
            }
        }
        return result;
    }

    friend Vector3<Type> operator*(const Matrix3& mat3, const Vector3<Type>& vec3) const
    {
        Vector3<Type> result;
        for (size_t row = 0; row < 3; row++)
        {
            result.data[row] = mat3.data[row][0] * vec3.x + mat3.data[row][1] * vec3.y + mat3.data[row][2] * vec3.z;
        }
        return result;
    }

    friend Vector3<Type> operator*(const Vector3<Type>& vec3, const Matrix3& mat3)
    {
        Vector3<Type> result;
        for (size_t row = 0; row < 3; row++)
        {
            result.data[row] = vec3.x * mat3.data[0][row] + vec3.y * mat3.data[1][row] + vec3.z * mat3.data[2][row];
        }
        return result;
    }
public:
    union
    {
        Type data[3][3];
    };
};
}// namespace Star