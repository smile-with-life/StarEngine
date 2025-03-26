#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
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
}// namespace Star