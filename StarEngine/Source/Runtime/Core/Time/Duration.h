#pragma once
#include "Runtime/Core/Core.h"

namespace Star
{
class Duration
{
public:
    Duration() = default;

    ~Duration() = default;

    Duration(const Duration& other) = default;

    Duration& operator=(const Duration& other) = default;

    Duration(Duration&& other) = default;

    Duration& operator=(Duration&& other) = default;

    explicit Duration(std::chrono::duration<int64, std::nano> ns)
        : count(ns)
    {

    }
public:
    int64 Years() const;

    int64 Months() const;

    int64 Days() const;

    int64 Hours() const;

    int64 Minutes() const;

    int64 Seconds() const;

    int64 Miliseconds() const;

    int64 Mircoseconds() const;

    int64 Nanoseconds() const;
public:
    // 纳秒作为计数周期
    std::chrono::duration<int64,std::nano> count{};
};

// 年
class Years
{
public:
    Years() = default;

    ~Years() = default;

    Years(const Years& other) = default;

    Years& operator=(const Years& other) = default;

    Years(Years&& other) = default;

    Years& operator=(Years&& other) = default;

    explicit Years(int64 year)
        : m_year(year)
    {

    }

    explicit Years(std::chrono::years year)
        : m_year(year)
    {

    }
public:
    friend Years operator+(const Years& left, const Years& right)
    {
        return Years(left.m_year + right.m_year);
    }

    friend Years operator-(const Years& left, const Years& right)
    {
        return Years(left.m_year - right.m_year);
    }

    friend Years operator*(const Years& left, int64 right)
    {
        return Years(left.m_year * right);
    }

    friend Years operator*(int64 left, const Years& right)
    {
        return Years(left * right.m_year);
    }

    friend Years operator/(const Years& left, const Years& right)
    {
        return Years(left.m_year / right.m_year);
    }

    friend Years operator/(const Years& left, int64 right)
    {
        return Years(left.m_year / right);
    }

    friend bool operator==(const Years& left, const Years& right)
    {
        return left.m_year == right.m_year;
    }

    friend bool operator==(const Years& left, const Duration& right)
    {
        return left.m_year == right.count;
    }

    friend bool operator==(const Duration& left, const Years& right)
    {
        return left.count == right.m_year;
    }

    friend bool operator==(const Years& left, int64 right)
    {
        return left.m_year.count() == right;
    }

    friend bool operator==(int64 left, const Years& right)
    {
        return left == right.m_year.count();
    }

    friend bool operator!=(const Years& left, const Years& right)
    {
        return left.m_year != right.m_year;
    }

    friend bool operator!=(const Years& left, const Duration& right)
    {
        return left.m_year != right.count;
    }

    friend bool operator!=(const Duration& left, const Years& right)
    {
        return left.count != right.m_year;
    }

    friend bool operator!=(const Years& left, int64 right)
    {
        return left.m_year.count() != right;
    }

    friend bool operator!=(int64 left, const Years& right)
    {
        return left != right.m_year.count();
    }

    friend bool operator>(const Years& left, const Years& right)
    {
        return left.m_year > right.m_year;
    }

    friend bool operator>(const Years& left, const Duration& right)
    {
        return left.m_year > right.count;
    }

    friend bool operator>(const Duration& left, const Years& right)
    {
        return left.count > right.m_year;
    }

    friend bool operator>(const Years& left, int64 right)
    {
        return left.m_year.count() > right;
    }

    friend bool operator>(int64 left, const Years& right)
    {
        return left > right.m_year.count();
    }

    friend bool operator>=(const Years& left, const Years& right)
    {
        return left.m_year >= right.m_year;
    }

    friend bool operator>=(const Years& left, const Duration& right)
    {
        return left.m_year >= right.count;
    }

    friend bool operator>=(const Duration& left, const Years& right)
    {
        return left.count >= right.m_year;
    }

    friend bool operator>=(const Years& left, int64 right)
    {
        return left.m_year.count() >= right;
    }

    friend bool operator>=(int64 left, const Years& right)
    {
        return left >= right.m_year.count();
    }

    friend bool operator<(const Years& left, const Years& right)
    {
        return left.m_year < right.m_year;
    }

    friend bool operator<(const Years& left, const Duration& right)
    {
        return left.m_year < right.count;
    }

    friend bool operator<(const Duration& left, const Years& right)
    {
        return left.count < right.m_year;
    }

    friend bool operator<(const Years& left, int64 right)
    {
        return left.m_year.count() < right;
    }

    friend bool operator<(int64 left, const Years& right)
    {
        return left < right.m_year.count();
    }

    friend bool operator<=(const Years& left, const Years& right)
    {
        return left.m_year <= right.m_year;
    }

    friend bool operator<=(const Years& left, const Duration& right)
    {
        return left.m_year <= right.count;
    }

    friend bool operator<=(const Duration& left, const Years& right)
    {
        return left.count <= right.m_year;
    }

    friend bool operator<=(const Years& left, int64 right)
    {
        return left.m_year.count() <= right;
    }

    friend bool operator<=(int64 left, const Years& right)
    {
        return left <= right.m_year.count();
    }
private:
    std::chrono::years m_year;
};

// 月
class Months
{
public:
    Months() = default;

    ~Months() = default;

    Months(const Months& other) = default;

    Months& operator=(const Months& other) = default;

    Months(Months&& other) = default;

    Months& operator=(Months&& other) = default;

    explicit Months(int64 month)
        : m_month(month)
    {

    }

    explicit Months(std::chrono::months month)
        : m_month(month)
    {

    }
public:
    friend Months operator+(const Months& left, const Months& right)
    {
        return Months(left.m_month + right.m_month);
    }

    friend Months operator-(const Months& left, const Months& right)
    {
        return Months(left.m_month - right.m_month);
    }

    friend Months operator*(const Months& left, int64 right)
    {
        return Months(left.m_month * right);
    }

    friend Months operator*(int64 left, const Months& right)
    {
        return Months(left * right.m_month);
    }

    friend Months operator/(const Months& left, const Months& right)
    {
        return Months(left.m_month / right.m_month);
    }

    friend Months operator/(const Months& left, int64 right)
    {
        return Months(left.m_month / right);
    }

    friend bool operator==(const Months& left, const Months& right)
    {
        return left.m_month == right.m_month;
    }

    friend bool operator==(const Months& left, const Duration& right)
    {
        return left.m_month == right.count;
    }

    friend bool operator==(const Duration& left, const Months& right)
    {
        return left.count == right.m_month;
    }

    friend bool operator==(const Months& left, int64 right)
    {
        return left.m_month.count() == right;
    }

    friend bool operator==(int64 left, const Months& right)
    {
        return left == right.m_month.count();
    }

    friend bool operator!=(const Months& left, const Months& right)
    {
        return left.m_month != right.m_month;
    }

    friend bool operator!=(const Months& left, const Duration& right)
    {
        return left.m_month != right.count;
    }

    friend bool operator!=(const Duration& left, const Months& right)
    {
        return left.count != right.m_month;
    }

    friend bool operator!=(const Months& left, int64 right)
    {
        return left.m_month.count() != right;
    }

    friend bool operator!=(int64 left, const Months& right)
    {
        return left != right.m_month.count();
    }

    friend bool operator>(const Months& left, const Months& right)
    {
        return left.m_month > right.m_month;
    }

    friend bool operator>(const Months& left, const Duration& right)
    {
        return left.m_month > right.count;
    }

    friend bool operator>(const Duration& left, const Months& right)
    {
        return left.count > right.m_month;
    }

    friend bool operator>(const Months& left, int64 right)
    {
        return left.m_month.count() > right;
    }

    friend bool operator>(int64 left, const Months& right)
    {
        return left > right.m_month.count();
    }

    friend bool operator>=(const Months& left, const Months& right)
    {
        return left.m_month >= right.m_month;
    }

    friend bool operator>=(const Months& left, const Duration& right)
    {
        return left.m_month >= right.count;
    }

    friend bool operator>=(const Duration& left, const Months& right)
    {
        return left.count >= right.m_month;
    }

    friend bool operator>=(const Months& left, int64 right)
    {
        return left.m_month.count() >= right;
    }

    friend bool operator>=(int64 left, const Months& right)
    {
        return left >= right.m_month.count();
    }

    friend bool operator<(const Months& left, const Months& right)
    {
        return left.m_month < right.m_month;
    }

    friend bool operator<(const Months& left, const Duration& right)
    {
        return left.m_month < right.count;
    }

    friend bool operator<(const Duration& left, const Months& right)
    {
        return left.count < right.m_month;
    }

    friend bool operator<(const Months& left, int64 right)
    {
        return left.m_month.count() < right;
    }

    friend bool operator<(int64 left, const Months& right)
    {
        return left < right.m_month.count();
    }

    friend bool operator<=(const Months& left, const Months& right)
    {
        return left.m_month <= right.m_month;
    }

    friend bool operator<=(const Months& left, const Duration& right)
    {
        return left.m_month <= right.count;
    }

    friend bool operator<=(const Duration& left, const Months& right)
    {
        return left.count <= right.m_month;
    }

    friend bool operator<=(const Months& left, int64 right)
    {
        return left.m_month.count() <= right;
    }

    friend bool operator<=(int64 left, const Months& right)
    {
        return left <= right.m_month.count();
    }
private:
    std::chrono::months m_month;
};

// 日
class Days
{
public:
    Days() = default;

    ~Days() = default;

    Days(const Days& other) = default;

    Days& operator=(const Days& other) = default;

    Days(Days&& other) = default;

    Days& operator=(Days&& other) = default;

    explicit Days(int64 day)
        : m_day(day)
    {

    }

    explicit Days(std::chrono::days day)
        : m_day(day)
    {

    }
public:
    friend Days operator+(const Days& left, const Days& right)
    {
        return Days(left.m_day + right.m_day);
    }

    friend Days operator-(const Days& left, const Days& right)
    {
        return Days(left.m_day - right.m_day);
    }

    friend Days operator*(const Days& left, int64 right)
    {
        return Days(left.m_day * right);
    }

    friend Days operator*(int64 left, const Days& right)
    {
        return Days(left * right.m_day);
    }

    friend Days operator/(const Days& left, const Days& right)
    {
        return Days(left.m_day / right.m_day);
    }

    friend Days operator/(const Days& left, int64 right)
    {
        return Days(left.m_day / right);
    }

    friend bool operator==(const Days& left, const Days& right)
    {
        return left.m_day == right.m_day;
    }

    friend bool operator==(const Days& left, const Duration& right)
    {
        return left.m_day == right.count;
    }

    friend bool operator==(const Duration& left, const Days& right)
    {
        return left.count == right.m_day;
    }

    friend bool operator==(const Days& left, int64 right)
    {
        return left.m_day.count() == right;
    }

    friend bool operator==(int64 left, const Days& right)
    {
        return left == right.m_day.count();
    }

    friend bool operator!=(const Days& left, const Days& right)
    {
        return left.m_day != right.m_day;
    }

    friend bool operator!=(const Days& left, const Duration& right)
    {
        return left.m_day != right.count;
    }

    friend bool operator!=(const Duration& left, const Days& right)
    {
        return left.count != right.m_day;
    }

    friend bool operator!=(const Days& left, int64 right)
    {
        return left.m_day.count() != right;
    }

    friend bool operator!=(int64 left, const Days& right)
    {
        return left != right.m_day.count();
    }

    friend bool operator>(const Days& left, const Days& right)
    {
        return left.m_day > right.m_day;
    }

    friend bool operator>(const Days& left, const Duration& right)
    {
        return left.m_day > right.count;
    }

    friend bool operator>(const Duration& left, const Days& right)
    {
        return left.count > right.m_day;
    }

    friend bool operator>(const Days& left, int64 right)
    {
        return left.m_day.count() > right;
    }

    friend bool operator>(int64 left, const Days& right)
    {
        return left > right.m_day.count();
    }

    friend bool operator>=(const Days& left, const Days& right)
    {
        return left.m_day >= right.m_day;
    }

    friend bool operator>=(const Days& left, const Duration& right)
    {
        return left.m_day >= right.count;
    }

    friend bool operator>=(const Duration& left, const Days& right)
    {
        return left.count >= right.m_day;
    }

    friend bool operator>=(const Days& left, int64 right)
    {
        return left.m_day.count() >= right;
    }

    friend bool operator>=(int64 left, const Days& right)
    {
        return left >= right.m_day.count();
    }

    friend bool operator<(const Days& left, const Days& right)
    {
        return left.m_day < right.m_day;
    }

    friend bool operator<(const Days& left, const Duration& right)
    {
        return left.m_day < right.count;
    }

    friend bool operator<(const Duration& left, const Days& right)
    {
        return left.count < right.m_day;
    }

    friend bool operator<(const Days& left, int64 right)
    {
        return left.m_day.count() < right;
    }

    friend bool operator<(int64 left, const Days& right)
    {
        return left < right.m_day.count();
    }

    friend bool operator<=(const Days& left, const Days& right)
    {
        return left.m_day <= right.m_day;
    }

    friend bool operator<=(const Days& left, const Duration& right)
    {
        return left.m_day <= right.count;
    }

    friend bool operator<=(const Duration& left, const Days& right)
    {
        return left.count <= right.m_day;
    }

    friend bool operator<=(const Days& left, int64 right)
    {
        return left.m_day.count() <= right;
    }

    friend bool operator<=(int64 left, const Days& right)
    {
        return left <= right.m_day.count();
    }
private:
    std::chrono::days m_day;
};

// 小时
class Hours
{
public:
    Hours() = default;

    ~Hours() = default;

    Hours(const Hours& other) = default;

    Hours& operator=(const Hours& other) = default;

    Hours(Hours&& other) = default;

    Hours& operator=(Hours&& other) = default;

    explicit Hours(int64 hour)
        : m_hour(hour)
    {

    }

    explicit Hours(std::chrono::hours hour)
        : m_hour(hour)
    {

    }
public:
    friend Hours operator+(const Hours& left, const Hours& right)
    {
        return Hours(left.m_hour + right.m_hour);
    }

    friend Hours operator-(const Hours& left, const Hours& right)
    {
        return Hours(left.m_hour - right.m_hour);
    }

    friend Hours operator*(const Hours& left, int64 right)
    {
        return Hours(left.m_hour * right);
    }

    friend Hours operator*(int64 left, const Hours& right)
    {
        return Hours(left * right.m_hour);
    }

    friend Hours operator/(const Hours& left, const Hours& right)
    {
        return Hours(left.m_hour / right.m_hour);
    }

    friend Hours operator/(const Hours& left, int64 right)
    {
        return Hours(left.m_hour / right);
    }

    friend bool operator==(const Hours& left, const Hours& right)
    {
        return left.m_hour == right.m_hour;
    }

    friend bool operator==(const Hours& left, const Duration& right)
    {
        return left.m_hour == right.count;
    }

    friend bool operator==(const Duration& left, const Hours& right)
    {
        return left.count == right.m_hour;
    }

    friend bool operator==(const Hours& left, int64 right)
    {
        return left.m_hour.count() == right;
    }

    friend bool operator==(int64 left, const Hours& right)
    {
        return left == right.m_hour.count();
    }

    friend bool operator!=(const Hours& left, const Hours& right)
    {
        return left.m_hour != right.m_hour;
    }

    friend bool operator!=(const Hours& left, const Duration& right)
    {
        return left.m_hour != right.count;
    }

    friend bool operator!=(const Duration& left, const Hours& right)
    {
        return left.count != right.m_hour;
    }

    friend bool operator!=(const Hours& left, int64 right)
    {
        return left.m_hour.count() != right;
    }

    friend bool operator!=(int64 left, const Hours& right)
    {
        return left != right.m_hour.count();
    }

    friend bool operator>(const Hours& left, const Hours& right)
    {
        return left.m_hour > right.m_hour;
    }

    friend bool operator>(const Hours& left, const Duration& right)
    {
        return left.m_hour > right.count;
    }

    friend bool operator>(const Duration& left, const Hours& right)
    {
        return left.count > right.m_hour;
    }

    friend bool operator>(const Hours& left, int64 right)
    {
        return left.m_hour.count() > right;
    }

    friend bool operator>(int64 left, const Hours& right)
    {
        return left > right.m_hour.count();
    }

    friend bool operator>=(const Hours& left, const Hours& right)
    {
        return left.m_hour >= right.m_hour;
    }

    friend bool operator>=(const Hours& left, const Duration& right)
    {
        return left.m_hour >= right.count;
    }

    friend bool operator>=(const Duration& left, const Hours& right)
    {
        return left.count >= right.m_hour;
    }

    friend bool operator>=(const Hours& left, int64 right)
    {
        return left.m_hour.count() >= right;
    }

    friend bool operator>=(int64 left, const Hours& right)
    {
        return left >= right.m_hour.count();
    }

    friend bool operator<(const Hours& left, const Hours& right)
    {
        return left.m_hour < right.m_hour;
    }

    friend bool operator<(const Hours& left, const Duration& right)
    {
        return left.m_hour < right.count;
    }

    friend bool operator<(const Duration& left, const Hours& right)
    {
        return left.count < right.m_hour;
    }

    friend bool operator<(const Hours& left, int64 right)
    {
        return left.m_hour.count() < right;
    }

    friend bool operator<(int64 left, const Hours& right)
    {
        return left < right.m_hour.count();
    }

    friend bool operator<=(const Hours& left, const Hours& right)
    {
        return left.m_hour <= right.m_hour;
    }

    friend bool operator<=(const Hours& left, const Duration& right)
    {
        return left.m_hour <= right.count;
    }

    friend bool operator<=(const Duration& left, const Hours& right)
    {
        return left.count <= right.m_hour;
    }

    friend bool operator<=(const Hours& left, int64 right)
    {
        return left.m_hour.count() <= right;
    }

    friend bool operator<=(int64 left, const Hours& right)
    {
        return left <= right.m_hour.count();
    }
private:
    std::chrono::hours m_hour;
};

// 分钟
class Minutes
{
public:
    Minutes() = default;

    ~Minutes() = default;

    Minutes(const Minutes& other) = default;

    Minutes& operator=(const Minutes& other) = default;

    Minutes(Minutes&& other) = default;

    Minutes& operator=(Minutes&& other) = default;

    explicit Minutes(int64 minute)
        : m_minute(minute)
    {

    }

    explicit Minutes(std::chrono::minutes minute)
        : m_minute(minute)
    {

    }
public:
    friend Minutes operator+(const Minutes& left, const Minutes& right)
    {
        return Minutes(left.m_minute + right.m_minute);
    }

    friend Minutes operator-(const Minutes& left, const Minutes& right)
    {
        return Minutes(left.m_minute - right.m_minute);
    }

    friend Minutes operator*(const Minutes& left, int64 right)
    {
        return Minutes(left.m_minute * right);
    }

    friend Minutes operator*(int64 left, const Minutes& right)
    {
        return Minutes(left * right.m_minute);
    }

    friend Minutes operator/(const Minutes& left, const Minutes& right)
    {
        return Minutes(left.m_minute / right.m_minute);
    }

    friend Minutes operator/(const Minutes& left, int64 right)
    {
        return Minutes(left.m_minute / right);
    }

    friend bool operator==(const Minutes& left, const Minutes& right)
    {
        return left.m_minute == right.m_minute;
    }

    friend bool operator==(const Minutes& left, const Duration& right)
    {
        return left.m_minute == right.count;
    }

    friend bool operator==(const Duration& left, const Minutes& right)
    {
        return left.count == right.m_minute;
    }

    friend bool operator==(const Minutes& left, int64 right)
    {
        return left.m_minute.count() == right;
    }

    friend bool operator==(int64 left, const Minutes& right)
    {
        return left == right.m_minute.count();
    }

    friend bool operator!=(const Minutes& left, const Minutes& right)
    {
        return left.m_minute != right.m_minute;
    }

    friend bool operator!=(const Minutes& left, const Duration& right)
    {
        return left.m_minute != right.count;
    }

    friend bool operator!=(const Duration& left, const Minutes& right)
    {
        return left.count != right.m_minute;
    }

    friend bool operator!=(const Minutes& left, int64 right)
    {
        return left.m_minute.count() != right;
    }

    friend bool operator!=(int64 left, const Minutes& right)
    {
        return left != right.m_minute.count();
    }

    friend bool operator>(const Minutes& left, const Minutes& right)
    {
        return left.m_minute > right.m_minute;
    }

    friend bool operator>(const Minutes& left, const Duration& right)
    {
        return left.m_minute > right.count;
    }

    friend bool operator>(const Duration& left, const Minutes& right)
    {
        return left.count > right.m_minute;
    }

    friend bool operator>(const Minutes& left, int64 right)
    {
        return left.m_minute.count() > right;
    }

    friend bool operator>(int64 left, const Minutes& right)
    {
        return left > right.m_minute.count();
    }

    friend bool operator>=(const Minutes& left, const Minutes& right)
    {
        return left.m_minute >= right.m_minute;
    }

    friend bool operator>=(const Minutes& left, const Duration& right)
    {
        return left.m_minute >= right.count;
    }

    friend bool operator>=(const Duration& left, const Minutes& right)
    {
        return left.count >= right.m_minute;
    }

    friend bool operator>=(const Minutes& left, int64 right)
    {
        return left.m_minute.count() >= right;
    }

    friend bool operator>=(int64 left, const Minutes& right)
    {
        return left >= right.m_minute.count();
    }

    friend bool operator<(const Minutes& left, const Minutes& right)
    {
        return left.m_minute < right.m_minute;
    }

    friend bool operator<(const Minutes& left, const Duration& right)
    {
        return left.m_minute < right.count;
    }

    friend bool operator<(const Duration& left, const Minutes& right)
    {
        return left.count < right.m_minute;
    }

    friend bool operator<(const Minutes& left, int64 right)
    {
        return left.m_minute.count() < right;
    }

    friend bool operator<(int64 left, const Minutes& right)
    {
        return left < right.m_minute.count();
    }

    friend bool operator<=(const Minutes& left, const Minutes& right)
    {
        return left.m_minute <= right.m_minute;
    }

    friend bool operator<=(const Minutes& left, const Duration& right)
    {
        return left.m_minute <= right.count;
    }

    friend bool operator<=(const Duration& left, const Minutes& right)
    {
        return left.count <= right.m_minute;
    }

    friend bool operator<=(const Minutes& left, int64 right)
    {
        return left.m_minute.count() <= right;
    }

    friend bool operator<=(int64 left, const Minutes& right)
    {
        return left <= right.m_minute.count();
    }
private:
    std::chrono::minutes m_minute;
};

// 秒
class Seconds
{
public:
    Seconds() = default;

    ~Seconds() = default;

    Seconds(const Seconds& other) = default;

    Seconds& operator=(const Seconds& other) = default;

    Seconds(Seconds&& other) = default;

    Seconds& operator=(Seconds&& other) = default;

    explicit Seconds(int64 second)
        : m_second(second)
    {

    }

    explicit Seconds(std::chrono::seconds second)
        : m_second(second)
    {

    }
public:
    friend Seconds operator+(const Seconds& left, const Seconds& right)
    {
        return Seconds(left.m_second + right.m_second);
    }

    friend Seconds operator-(const Seconds& left, const Seconds& right)
    {
        return Seconds(left.m_second - right.m_second);
    }

    friend Seconds operator*(const Seconds& left, int64 right)
    {
        return Seconds(left.m_second * right);
    }

    friend Seconds operator*(int64 left, const Seconds& right)
    {
        return Seconds(left * right.m_second);
    }

    friend Seconds operator/(const Seconds& left, const Seconds& right)
    {
        return Seconds(left.m_second / right.m_second);
    }

    friend Seconds operator/(const Seconds& left, int64 right)
    {
        return Seconds(left.m_second / right);
    }

    friend bool operator==(const Seconds& left, const Seconds& right)
    {
        return left.m_second == right.m_second;
    }

    friend bool operator==(const Seconds& left, const Duration& right)
    {
        return left.m_second == right.count;
    }

    friend bool operator==(const Duration& left, const Seconds& right)
    {
        return left.count == right.m_second;
    }

    friend bool operator==(const Seconds& left, int64 right)
    {
        return left.m_second.count() == right;
    }

    friend bool operator==(int64 left, const Seconds& right)
    {
        return left == right.m_second.count();
    }

    friend bool operator!=(const Seconds& left, const Seconds& right)
    {
        return left.m_second != right.m_second;
    }

    friend bool operator!=(const Seconds& left, const Duration& right)
    {
        return left.m_second != right.count;
    }

    friend bool operator!=(const Duration& left, const Seconds& right)
    {
        return left.count != right.m_second;
    }

    friend bool operator!=(const Seconds& left, int64 right)
    {
        return left.m_second.count() != right;
    }

    friend bool operator!=(int64 left, const Seconds& right)
    {
        return left != right.m_second.count();
    }

    friend bool operator>(const Seconds& left, const Seconds& right)
    {
        return left.m_second > right.m_second;
    }

    friend bool operator>(const Seconds& left, const Duration& right)
    {
        return left.m_second > right.count;
    }

    friend bool operator>(const Duration& left, const Seconds& right)
    {
        return left.count > right.m_second;
    }

    friend bool operator>(const Seconds& left, int64 right)
    {
        return left.m_second.count() > right;
    }

    friend bool operator>(int64 left, const Seconds& right)
    {
        return left > right.m_second.count();
    }

    friend bool operator>=(const Seconds& left, const Seconds& right)
    {
        return left.m_second >= right.m_second;
    }

    friend bool operator>=(const Seconds& left, const Duration& right)
    {
        return left.m_second >= right.count;
    }

    friend bool operator>=(const Duration& left, const Seconds& right)
    {
        return left.count >= right.m_second;
    }

    friend bool operator>=(const Seconds& left, int64 right)
    {
        return left.m_second.count() >= right;
    }

    friend bool operator>=(int64 left, const Seconds& right)
    {
        return left >= right.m_second.count();
    }

    friend bool operator<(const Seconds& left, const Seconds& right)
    {
        return left.m_second < right.m_second;
    }

    friend bool operator<(const Seconds& left, const Duration& right)
    {
        return left.m_second < right.count;
    }

    friend bool operator<(const Duration& left, const Seconds& right)
    {
        return left.count < right.m_second;
    }

    friend bool operator<(const Seconds& left, int64 right)
    {
        return left.m_second.count() < right;
    }

    friend bool operator<(int64 left, const Seconds& right)
    {
        return left < right.m_second.count();
    }

    friend bool operator<=(const Seconds& left, const Seconds& right)
    {
        return left.m_second <= right.m_second;
    }

    friend bool operator<=(const Seconds& left, const Duration& right)
    {
        return left.m_second <= right.count;
    }

    friend bool operator<=(const Duration& left, const Seconds& right)
    {
        return left.count <= right.m_second;
    }

    friend bool operator<=(const Seconds& left, int64 right)
    {
        return left.m_second.count() <= right;
    }

    friend bool operator<=(int64 left, const Seconds& right)
    {
        return left <= right.m_second.count();
    }
private:
    std::chrono::seconds m_second{};
};

// 毫秒
class Milliseconds
{
public:
    Milliseconds() = default;

    ~Milliseconds() = default;

    Milliseconds(const Milliseconds& other) = default;

    Milliseconds& operator=(const Milliseconds& other) = default;

    Milliseconds(Milliseconds&& other) = default;

    Milliseconds& operator=(Milliseconds&& other) = default;

    explicit Milliseconds(int64 ms)
        : m_milli(ms)
    {

    }

    explicit Milliseconds(std::chrono::milliseconds ms)
        : m_milli(ms)
    {

    }
public:
    friend Milliseconds operator+(const Milliseconds& left, const Milliseconds& right)
    {
        return Milliseconds(left.m_milli + right.m_milli);
    }

    friend Milliseconds operator-(const Milliseconds& left, const Milliseconds& right)
    {
        return Milliseconds(left.m_milli - right.m_milli);
    }

    friend Milliseconds operator*(const Milliseconds& left, int64 right)
    {
        return Milliseconds(left.m_milli * right);
    }

    friend Milliseconds operator*(int64 left, const Milliseconds& right)
    {
        return Milliseconds(left * right.m_milli);
    }

    friend Milliseconds operator/(const Milliseconds& left, const Milliseconds& right)
    {
        return Milliseconds(left.m_milli / right.m_milli);
    }

    friend Milliseconds operator/(const Milliseconds& left, int64 right)
    {
        return Milliseconds(left.m_milli / right);
    }

    friend bool operator==(const Milliseconds& left, const Milliseconds& right)
    {
        return left.m_milli == right.m_milli;
    }

    friend bool operator==(const Milliseconds& left, const Duration& right)
    {
        return left.m_milli == right.count;
    }

    friend bool operator==(const Duration& left, const Milliseconds& right)
    {
        return left.count == right.m_milli;
    }

    friend bool operator==(const Milliseconds& left, int64 right)
    {
        return left.m_milli.count() == right;
    }

    friend bool operator==(int64 left, const Milliseconds& right)
    {
        return left == right.m_milli.count();
    }

    friend bool operator!=(const Milliseconds& left, const Milliseconds& right)
    {
        return left.m_milli != right.m_milli;
    }

    friend bool operator!=(const Milliseconds& left, const Duration& right)
    {
        return left.m_milli != right.count;
    }

    friend bool operator!=(const Duration& left, const Milliseconds& right)
    {
        return left.count != right.m_milli;
    }

    friend bool operator!=(const Milliseconds& left, int64 right)
    {
        return left.m_milli.count() != right;
    }

    friend bool operator!=(int64 left, const Milliseconds& right)
    {
        return left != right.m_milli.count();
    }

    friend bool operator>(const Milliseconds& left, const Milliseconds& right)
    {
        return left.m_milli > right.m_milli;
    }

    friend bool operator>(const Milliseconds& left, const Duration& right)
    {
        return left.m_milli > right.count;
    }

    friend bool operator>(const Duration& left, const Milliseconds& right)
    {
        return left.count > right.m_milli;
    }

    friend bool operator>(const Milliseconds& left, int64 right)
    {
        return left.m_milli.count() > right;
    }

    friend bool operator>(int64 left, const Milliseconds& right)
    {
        return left > right.m_milli.count();
    }

    friend bool operator>=(const Milliseconds& left, const Milliseconds& right)
    {
        return left.m_milli >= right.m_milli;
    }

    friend bool operator>=(const Milliseconds& left, const Duration& right)
    {
        return left.m_milli >= right.count;
    }

    friend bool operator>=(const Duration& left, const Milliseconds& right)
    {
        return left.count >= right.m_milli;
    }

    friend bool operator>=(const Milliseconds& left, int64 right)
    {
        return left.m_milli.count() >= right;
    }

    friend bool operator>=(int64 left, const Milliseconds& right)
    {
        return left >= right.m_milli.count();
    }

    friend bool operator<(const Milliseconds& left, const Milliseconds& right)
    {
        return left.m_milli < right.m_milli;
    }

    friend bool operator<(const Milliseconds& left, const Duration& right)
    {
        return left.m_milli < right.count;
    }

    friend bool operator<(const Duration& left, const Milliseconds& right)
    {
        return left.count < right.m_milli;
    }

    friend bool operator<(const Milliseconds& left, int64 right)
    {
        return left.m_milli.count() < right;
    }

    friend bool operator<(int64 left, const Milliseconds& right)
    {
        return left < right.m_milli.count();
    }

    friend bool operator<=(const Milliseconds& left, const Milliseconds& right)
    {
        return left.m_milli <= right.m_milli;
    }

    friend bool operator<=(const Milliseconds& left, const Duration& right)
    {
        return left.m_milli <= right.count;
    }

    friend bool operator<=(const Duration& left, const Milliseconds& right)
    {
        return left.count <= right.m_milli;
    }

    friend bool operator<=(const Milliseconds& left, int64 right)
    {
        return left.m_milli.count() <= right;
    }

    friend bool operator<=(int64 left, const Milliseconds& right)
    {
        return left <= right.m_milli.count();
    }
private:
    std::chrono::milliseconds m_milli{};
};

// 微妙
class Microseconds
{
public:
    Microseconds() = default;

    ~Microseconds() = default;

    Microseconds(const Microseconds& other) = default;

    Microseconds& operator=(const Microseconds& other) = default;

    Microseconds(Microseconds&& other) = default;

    Microseconds& operator=(Microseconds&& other) = default;

    explicit Microseconds(int64 us)
        : m_micro(us)
    {

    }

    explicit Microseconds(std::chrono::microseconds us)
        : m_micro(us)
    {

    }
public:
    friend Microseconds operator+(const Microseconds& left, const Microseconds& right)
    {
        return Microseconds(left.m_micro + right.m_micro);
    }

    friend Microseconds operator-(const Microseconds& left, const Microseconds& right)
    {
        return Microseconds(left.m_micro - right.m_micro);
    }

    friend Microseconds operator*(const Microseconds& left, int64 right)
    {
        return Microseconds(left.m_micro * right);
    }

    friend Microseconds operator*(int64 left, const Microseconds& right)
    {
        return Microseconds(left * right.m_micro);
    }

    friend Microseconds operator/(const Microseconds& left, const Microseconds& right)
    {
        return Microseconds(left.m_micro / right.m_micro);
    }

    friend Microseconds operator/(const Microseconds& left, int64 right)
    {
        return Microseconds(left.m_micro / right);
    }

    friend bool operator==(const Microseconds& left, const Microseconds& right)
    {
        return left.m_micro == right.m_micro;
    }

    friend bool operator==(const Microseconds& left, const Duration& right)
    {
        return left.m_micro == right.count;
    }

    friend bool operator==(const Duration& left, const Microseconds& right)
    {
        return left.count == right.m_micro;
    }

    friend bool operator==(const Microseconds& left, int64 right)
    {
        return left.m_micro.count() == right;
    }

    friend bool operator==(int64 left, const Microseconds& right)
    {
        return left == right.m_micro.count();
    }

    friend bool operator!=(const Microseconds& left, const Microseconds& right)
    {
        return left.m_micro != right.m_micro;
    }

    friend bool operator!=(const Microseconds& left, const Duration& right)
    {
        return left.m_micro != right.count;
    }

    friend bool operator!=(const Duration& left, const Microseconds& right)
    {
        return left.count != right.m_micro;
    }

    friend bool operator!=(const Microseconds& left, int64 right)
    {
        return left.m_micro.count() != right;
    }

    friend bool operator!=(int64 left, const Microseconds& right)
    {
        return left != right.m_micro.count();
    }

    friend bool operator>(const Microseconds& left, const Microseconds& right)
    {
        return left.m_micro > right.m_micro;
    }

    friend bool operator>(const Microseconds& left, const Duration& right)
    {
        return left.m_micro > right.count;
    }

    friend bool operator>(const Duration& left, const Microseconds& right)
    {
        return left.count > right.m_micro;
    }

    friend bool operator>(const Microseconds& left, int64 right)
    {
        return left.m_micro.count() > right;
    }

    friend bool operator>(int64 left, const Microseconds& right)
    {
        return left > right.m_micro.count();
    }

    friend bool operator>=(const Microseconds& left, const Microseconds& right)
    {
        return left.m_micro >= right.m_micro;
    }

    friend bool operator>=(const Microseconds& left, const Duration& right)
    {
        return left.m_micro >= right.count;
    }

    friend bool operator>=(const Duration& left, const Microseconds& right)
    {
        return left.count >= right.m_micro;
    }

    friend bool operator>=(const Microseconds& left, int64 right)
    {
        return left.m_micro.count() >= right;
    }

    friend bool operator>=(int64 left, const Microseconds& right)
    {
        return left >= right.m_micro.count();
    }

    friend bool operator<(const Microseconds& left, const Microseconds& right)
    {
        return left.m_micro < right.m_micro;
    }

    friend bool operator<(const Microseconds& left, const Duration& right)
    {
        return left.m_micro < right.count;
    }

    friend bool operator<(const Duration& left, const Microseconds& right)
    {
        return left.count < right.m_micro;
    }

    friend bool operator<(const Microseconds& left, int64 right)
    {
        return left.m_micro.count() < right;
    }

    friend bool operator<(int64 left, const Microseconds& right)
    {
        return left < right.m_micro.count();
    }

    friend bool operator<=(const Microseconds& left, const Microseconds& right)
    {
        return left.m_micro <= right.m_micro;
    }

    friend bool operator<=(const Microseconds& left, const Duration& right)
    {
        return left.m_micro <= right.count;
    }

    friend bool operator<=(const Duration& left, const Microseconds& right)
    {
        return left.count <= right.m_micro;
    }

    friend bool operator<=(const Microseconds& left, int64 right)
    {
        return left.m_micro.count() <= right;
    }

    friend bool operator<=(int64 left, const Microseconds& right)
    {
        return left <= right.m_micro.count();
    }
private:
    std::chrono::microseconds m_micro{};
};

// 纳秒
class Nanoseconds
{
public:
    Nanoseconds() = default;

    ~Nanoseconds() = default;

    Nanoseconds(const Nanoseconds& other) = default;

    Nanoseconds& operator=(const Nanoseconds& other) = default;

    Nanoseconds(Nanoseconds&& other) = default;

    Nanoseconds& operator=(Nanoseconds&& other) = default;

    explicit Nanoseconds(int64 ns)
        : m_nano(ns)
    {

    }

    explicit Nanoseconds(std::chrono::nanoseconds ns)
        : m_nano(ns)
    {

    }
public:
    friend Nanoseconds operator+(const Nanoseconds& left, const Nanoseconds& right)
    {
        return Nanoseconds(left.m_nano + right.m_nano);
    }

    friend Nanoseconds operator-(const Nanoseconds& left, const Nanoseconds& right)
    {
        return Nanoseconds(left.m_nano - right.m_nano);
    }

    friend Nanoseconds operator*(const Nanoseconds& left, int64 right)
    {
        return Nanoseconds(left.m_nano * right);
    }

    friend Nanoseconds operator*(int64 left, const Nanoseconds& right)
    {
        return Nanoseconds(left * right.m_nano);
    }

    friend Nanoseconds operator/(const Nanoseconds& left, const Nanoseconds& right)
    {
        return Nanoseconds(left.m_nano / right.m_nano);
    }

    friend Nanoseconds operator/(const Nanoseconds& left, int64 right)
    {
        return Nanoseconds(left.m_nano / right);
    }

    friend bool operator==(const Nanoseconds& left, const Nanoseconds& right)
    {
        return left.m_nano == right.m_nano;
    }

    friend bool operator==(const Nanoseconds& left, const Duration& right)
    {
        return left.m_nano == right.count;
    }

    friend bool operator==(const Duration& left, const Nanoseconds& right)
    {
        return left.count == right.m_nano;
    }

    friend bool operator==(const Nanoseconds& left, int64 right)
    {
        return left.m_nano.count() == right;
    }

    friend bool operator==(int64 left, const Nanoseconds& right)
    {
        return left == right.m_nano.count();
    }

    friend bool operator!=(const Nanoseconds& left, const Nanoseconds& right)
    {
        return left.m_nano != right.m_nano;
    }

    friend bool operator!=(const Nanoseconds& left, const Duration& right)
    {
        return left.m_nano != right.count;
    }

    friend bool operator!=(const Duration& left, const Nanoseconds& right)
    {
        return left.count != right.m_nano;
    }

    friend bool operator!=(const Nanoseconds& left, int64 right)
    {
        return left.m_nano.count() != right;
    }

    friend bool operator!=(int64 left, const Nanoseconds& right)
    {
        return left != right.m_nano.count();
    }

    friend bool operator>(const Nanoseconds& left, const Nanoseconds& right)
    {
        return left.m_nano > right.m_nano;
    }

    friend bool operator>(const Nanoseconds& left, const Duration& right)
    {
        return left.m_nano > right.count;
    }

    friend bool operator>(const Duration& left, const Nanoseconds& right)
    {
        return left.count > right.m_nano;
    }

    friend bool operator>(const Nanoseconds& left, int64 right)
    {
        return left.m_nano.count() > right;
    }

    friend bool operator>(int64 left, const Nanoseconds& right)
    {
        return left > right.m_nano.count();
    }

    friend bool operator>=(const Nanoseconds& left, const Nanoseconds& right)
    {
        return left.m_nano >= right.m_nano;
    }

    friend bool operator>=(const Nanoseconds& left, const Duration& right)
    {
        return left.m_nano >= right.count;
    }

    friend bool operator>=(const Duration& left, const Nanoseconds& right)
    {
        return left.count >= right.m_nano;
    }

    friend bool operator>=(const Nanoseconds& left, int64 right)
    {
        return left.m_nano.count() >= right;
    }

    friend bool operator>=(int64 left, const Nanoseconds& right)
    {
        return left >= right.m_nano.count();
    }

    friend bool operator<(const Nanoseconds& left, const Nanoseconds& right)
    {
        return left.m_nano < right.m_nano;
    }

    friend bool operator<(const Nanoseconds& left, const Duration& right)
    {
        return left.m_nano < right.count;
    }

    friend bool operator<(const Duration& left, const Nanoseconds& right)
    {
        return left.count < right.m_nano;
    }

    friend bool operator<(const Nanoseconds& left, int64 right)
    {
        return left.m_nano.count() < right;
    }

    friend bool operator<(int64 left, const Nanoseconds& right)
    {
        return left < right.m_nano.count();
    }

    friend bool operator<=(const Nanoseconds& left, const Nanoseconds& right)
    {
        return left.m_nano <= right.m_nano;
    }

    friend bool operator<=(const Nanoseconds& left, const Duration& right)
    {
        return left.m_nano <= right.count;
    }

    friend bool operator<=(const Duration& left, const Nanoseconds& right)
    {
        return left.count <= right.m_nano;
    }

    friend bool operator<=(const Nanoseconds& left, int64 right)
    {
        return left.m_nano.count() <= right;
    }

    friend bool operator<=(int64 left, const Nanoseconds& right)
    {
        return left <= right.m_nano.count();
    }
private:
    std::chrono::nanoseconds m_nano{};
};
}// namespace Star