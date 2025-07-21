#pragma once
#include "Core/Core.h"
#include "Core/String/String.h"

namespace Star
{
// 时间和日期
class DateTime
{
public:
    // 默认构造函数
    DateTime() = default;

    // 析构函数
    ~DateTime() = default;

    // 拷贝构造函数
    DateTime(const DateTime& other) = default;

    // 拷贝赋值函数
    DateTime& operator=(const DateTime& other) = default;

    // 移动构造函数
    DateTime(DateTime&& other) = default;

    // 移动赋值函数
    DateTime& operator=(DateTime&& other) = default;

    // 构造函数
    DateTime(const String& iso8601);
public:
    // 年份
    int32 Year() const;

    // 月份
    int32 Month() const;

    // 天
    int32 Day() const;

    // 小时
    int32 Hour() const;

    // 分钟
    int32 Minute() const;

    // 秒
    int32 Second() const;

    // 转为字符串
    String ToString();

    // 交换
    void Swap(DateTime& other) noexcept;    
public:
    bool operator==(const DateTime& other);

    bool operator!=(const DateTime& other);

    bool operator>(const DateTime& other);

    bool operator>=(const DateTime& other);

    bool operator<(const DateTime& other);

    bool operator<=(const DateTime& other);
private:
    int32 m_year = -1;
    int32 m_month = -1;
    int32 m_day = -1;
    int32 m_hour = -1;
    int32 m_minute = -1;
    int32 m_second = -1;
};
}// namespace Star