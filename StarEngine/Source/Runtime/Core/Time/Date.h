#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
// 日期
class Date
{
public:
    // 默认构造函数
    Date();

    // 析构函数
    ~Date();

    // 拷贝构造函数
    Date(const Date& other);

    // 拷贝赋值函数
    Date& operator=(const Date& other);

    // 移动构造函数
    Date(Date&& other);

    // 移动赋值函数
    Date& operator=(Date&& other);
public:
    // 年份
    int32 Year();

    // 月份
    int32 Month();

    // 日期
    int32 Day();

    // 设置年份
    Date& SetYear();

    // 设置月份
    Date& SetMonth();

    // 设置日期
    Date& SetDay();

    // 转为字符串
    String ToString();
public:
    bool operator==(const Date& other);

    bool operator!=(const Date& other);

    bool operator>(const Date& other);

    bool operator>=(const Date& other);

    bool operator<(const Date& other);

    bool operator<=(const Date& other);
};
}// namespace Star