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

    // 天
    int32 Day();

    // 设置年份
    Date& SetYear();

    // 设置月份
    Date& SetMonth();

    // 设置天
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

// 时间
class Time
{
public:
    // 默认构造函数
    Time();

    // 析构函数
    ~Time();

    // 拷贝构造函数
    Time(const Time& other);

    // 拷贝赋值函数
    Time& operator=(const Time& other);

    // 移动构造函数
    Time(Time&& other);

    // 移动赋值函数
    Time& operator=(Time&& other);
public:
    // 小时
    int32 Hour();

    // 分钟
    int32 Minute();

    // 秒
    int32 Second();

    // 设置小时
    Time& SetHour();

    // 设置分钟
    Time& SetMinute();

    // 设置秒
    Time& SetSecond();

    // 转为字符串
    String ToString();
public:
    bool operator==(const Time& other);

    bool operator!=(const Time& other);

    bool operator>(const Time& other);

    bool operator>=(const Time& other);

    bool operator<(const Time& other);

    bool operator<=(const Time& other);
};

// 时间和日期
class DateTime
{
public:
    // 默认构造函数
    DateTime();

    // 析构函数
    ~DateTime();

    // 拷贝构造函数
    DateTime(const DateTime& other);

    // 拷贝赋值函数
    DateTime& operator=(const DateTime& other);

    // 移动构造函数
    DateTime(DateTime&& other);

    // 移动赋值函数
    DateTime& operator=(DateTime&& other);
public:
    // 年份
    int32 Year();

    // 月份
    int32 Month();

    // 天
    int32 Day();

    // 小时
    int32 Hour();

    // 分钟
    int32 Minute();

    // 秒
    int32 Second();

    // 日期部分
    Date Date();

    // 时间部分
    Time Time();

    // 设置年份
    DateTime& SetYear();

    // 设置月份
    DateTime& SetMonth();

    // 设置天
    DateTime& SetDay();

    // 设置小时
    DateTime& SetHour();

    // 设置分钟
    DateTime& SetMinute();

    // 设置秒
    DateTime& SetSecond();

    // 转为字符串
    String ToString();
public:
    bool operator==(const DateTime& other);

    bool operator!=(const DateTime& other);

    bool operator>(const DateTime& other);

    bool operator>=(const DateTime& other);

    bool operator<(const DateTime& other);

    bool operator<=(const DateTime& other);
private:
    std::chrono::year m_year;

};
}// namespace Star