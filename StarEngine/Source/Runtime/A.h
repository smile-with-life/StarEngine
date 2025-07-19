#pragma once

#include "Runtime/Core/Core.h"

namespace Star
{
class A
{
public:
    // 默认构造函数
    A() = default;

    // 析构函数
    ~A() = default;

    // 拷贝构造函数
    A(const A& other) = default;

    // 拷贝赋值函数
    A& operator=(const A& other) = default;

    // 移动构造函数
    A(A&& other) = default;

    // 移动赋值函数
    A& operator=(A&& other) = default;
private:

};
}// namespace Star