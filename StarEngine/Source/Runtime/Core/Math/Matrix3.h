#pragma once
#include"Runtime/Core/Core.h"
#include"Runtime/Core/Concept/Concept.h"

#include <initializer_list>
#include "Math.h"
#include "Vector3.h"

namespace Star
{
template<Concept::ArithmeticType Type>
class Matrix3
{
public:
    Matrix3();
    ~Matrix3();
    Matrix3(const Matrix3& other);
    Matrix3& operator=(const Matrix3& other);
    Matrix3(Matrix3&& other) noexcept;
    Matrix3& operator=(Matrix3&& other) noexcept;

    explicit Matrix3(Type arr[3][3]);

    explicit Matrix3(Type (&arr)[9]);

    Matrix3(const Vector3& row0, const Vector3& row1, const Vector3& row2);
public:
    void FromData(float(&float_array)[9]);
public:
    Type* operator[](size_t row) const 
    { 
        return (Type*)data[row];
    }
    // 两个矩阵相加
    friend Matrix3 operator+(const Matrix3& left, const Matrix3& right) const
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
public:
    union
    {
        Type data[3][3];
    };
};
}// namespace Star