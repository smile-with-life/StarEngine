#include "starpch.h"
#include "DateTime.h"

namespace Star
{
DateTime::DateTime(const String& iso8601)
{
    std::tm tm = {};
    std::istringstream ss(iso8601.ToStdString());
    ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%SZ");

    if (ss.fail()) 
    {
        // @log
        m_year = -1;
        m_month = -1;
        m_day = -1;
        m_hour = -1;
        m_minute = -1;
        m_second = -1;
    }
    else
    {
        m_year = tm.tm_year + 1900;
        m_month = tm.tm_mon + 1;
        m_day = tm.tm_mday;
        m_hour = tm.tm_hour;
        m_minute = tm.tm_min;
        m_second = tm.tm_sec;
    }
}

int32 DateTime::Year() const
{
    return m_year;
}

int32 DateTime::Month() const
{
    return m_month;
}

int32 DateTime::Day() const
{
    return m_day;
}

int32 DateTime::Hour() const
{
    return m_hour;
}

int32 DateTime::Minute() const
{
    return m_minute;
}

int32 DateTime::Second() const
{
    return m_second;
}

String DateTime::ToString()
{
    std::string result = std::format("{0}-{1}-{2} {3}:{4}:{5}", m_year, m_month, m_day, m_hour, m_minute, m_second);
    return String(result);
}

void DateTime::Swap(DateTime& other) noexcept
{  
    std::swap(m_year, other.m_year);
    std::swap(m_month, other.m_month);
    std::swap(m_day, other.m_day);
    std::swap(m_hour, other.m_hour);
    std::swap(m_minute, other.m_minute);
    std::swap(m_second, other.m_second);   
}
}// namespace Star