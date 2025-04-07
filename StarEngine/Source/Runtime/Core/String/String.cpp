#include "starpch.h"
#include "String.h"
#include "unicode/ustream.h"
#include "Convert.h"
#include "Runtime/Core/Math/Math.h"

namespace Star
{
/* static */
String String::FromStdString(const std::string& str)
{
    return String(str);
}

String String::FromCString(const char* str)
{
    return String(str);
}

String String::FromInt8(int8 value)
{
    return String(std::to_string(value));
}

String String::FromInt16(int16 value)
{
    return String(std::to_string(value));
}

String String::FromInt32(int32 value)
{
    return String(std::to_string(value));
}

String String::FromInt64(int64 value)
{
    return String(std::to_string(value));
}

String String::FromUInt8(uint8 value)
{
    return String(std::to_string(value));
}

String String::FromUInt16(uint16 value)
{
    return String(std::to_string(value));
}

String String::FromUInt32(uint32 value)
{
    return String(std::to_string(value));
}

String String::FromUInt64(uint64 value)
{
    return String(std::to_string(value));
}

String String::FromFloat(float value)
{
    return String(std::to_string(value));
}

String String::FromDouble(double value)
{
    return String(std::to_string(value));
}

String String::FromBool(bool value)
{
    return value ? String("true") : String("false");
}

/* member */
String::String(const String& other)
    : m_data(other.m_data)
{

}

String& String::operator=(const String& other)
{
    if (this == &other) [[unlikely]] 
    {
        return *this;
    }

    m_data = other.m_data;
    return *this;
}

String::String(String&& other)
    : m_data(std::move(other.m_data))
{

}

String& String::operator=(String&& other)
{
    if (this == &other) [[unlikely]]
    {
        return *this;
    }

    m_data = std::move(other.m_data);
    return *this;
}

String::String(const char* str)
    : m_data(str)
{
    
}

String& String::operator=(const char* str)
{
    m_data = str;
    return *this;
}

String::String(const std::string& str)
    : m_data(str)
{

}

String& String::operator=(const std::string& str)
{
    m_data = str;
    return *this;
}

String::String(const ByteArray& buffer)
{
    m_data.clear();

    for (int64 i = 0; i < buffer.Size(); ++i)
    {
        if (buffer[i] == '\0') break;
        m_data.push_back(buffer[i]);
    }
}

String& String::operator=(const ByteArray& buffer)
{
    m_data.clear();

    for (int64 i = 0; i < buffer.Size(); ++i)
    {
        if (buffer[i] == '\0') break;
        m_data.push_back(buffer[i]);
    }
    return *this;
}

String::operator std::string() const
{
    return m_data;
}

String::operator const char* () const
{
    return m_data.c_str();
}

String& String::Append(const String& str)
{
    m_data.append(str.m_data);
    return *this;
}

String& String::Append(char ch)
{
    m_data.append(1,ch);
    return *this;
}

String& String::Prepend(const String& str)
{
    m_data.insert(0, str.m_data);
    return *this;
}

String& String::Prepend(char ch)
{
    m_data.insert(0, 1, ch);
    return *this;
}

int32 String::Compare(const String& str) const
{
    return m_data.compare(str.m_data);
}

bool String::Contains(const String& str) const
{
    int64 index = m_data.find(str.m_data);

    if (index == std::string::npos)
    {
        return false;
    }

    return true;
}

int32 String::IndexOf(const String& str) const
{
    return m_data.find(str.m_data);
}

int32 String::LastIndexOf(const String& str) const
{
    return m_data.rfind(str.m_data);
}

bool String::StartsWith(const String& str) const
{
    return m_data.starts_with(str.m_data);
}

bool String::EndsWith(const String& str) const
{
    return m_data.ends_with(str.m_data);
}

String& String::Insert(int32 index, const String& str)
{
    m_data.insert(index, str.m_data);
    return *this;
}

String& String::Replace(int32 index, int32 n, const String& str)
{
    m_data.replace(index, n, str.m_data);
    return *this;
}

char& String::At(int32 index)
{
    return m_data.at(index);
}

char& String::operator[](int32 index)
{
    return m_data[index];
}

const char String::operator[](int32 index) const
{
    return m_data[index];
}

char& String::FrontChar()
{
    return m_data.front();
}

const char String::FrontChar() const
{
    return m_data.front();
}

char& String::BackChar()
{
    return m_data.back();
}

const char String::BackChar() const
{
    return m_data.back();
}

String& String::ChopLeft(int32 n)
{
    if (n < 0) 
    {
        return *this;
    } 

    if (n > m_data.size()) 
    {
        n = m_data.size(); 
    }

    m_data.erase(0, n);
    return *this;
}

String& String::ChopMid(int32 index, int32 n)
{

    if (index < 0 || index > m_data.size() || n < 0)
    {
        return *this;
    }

    if (index + n > m_data.size())
    {
        n = m_data.size() - index;
    }

    m_data.erase(index, n);
    return *this;
}

String& String::ChopRight(int32 n)
{
    if (n < 0) 
    {
        return *this;
    }

    if (n > m_data.size())
    {
        n = m_data.size();
    }

    m_data.erase(m_data.size() - n, n);
    return *this;
}

String& String::RemianLeft(int32 n)
{
    if (n < 0 || n > m_data.size())
    {
        return *this;
    }

    ChopRight(m_data.size() - n);
    return *this;
}

String& String::RemianMid(int32 index, int32 n)
{
    if (index < 0 || index > m_data.size() || n < 0)
    {
        return *this;
    }

    ChopLeft(index);

    if (n > m_data.size())
    {
        n = m_data.size() - index;
    }

    Resize(n);  
    return *this;
}

String& String::RemianRight(int32 n)
{
    if (n < 0 || n > m_data.size())
    {
        return *this;
    }

    ChopLeft(m_data.size() - n);
    return *this;
}

String String::LeftStr(int32 n)
{
    if (n < 0) 
    {
        return String();
    }

    return String(m_data.substr(0, n));
}

String String::MidStr(int32 index, int32 n)
{
    if (index < 0 || index > m_data.size() || n < 0)
    {
        return String();
    }

    if (n > m_data.size())
    {
        n = m_data.size() - index;
    }

    return String(m_data.substr(index, n));
}

String String::SubStr(int64 start, int64 end)
{
    int n = end - start;
    if (n < 0)
    {
        // @ log
        return String();
    }

    return MidStr(start, n);
}

String String::RightStr(int32 n)
{
    if (n < 0) 
    {
        return String();
    }
 
    if (n > m_data.size()) 
    {
        return String(m_data);
    }

    return String(m_data.substr(m_data.size() - n));
}

String String::Match(char start, char end)
{
   int64 startIndex = m_data.find(start);
   int64 endIndex = m_data.find(end, startIndex + 1);
   return SubStr(startIndex + 1, endIndex);
}

void String::Clear()
{
    m_data.clear();
}

int32 String::Capacity() const
{
    return m_data.capacity();
}

int32 String::Size() const
{
    return m_data.size();
}

void String::Reserve(int32 size)
{
    m_data.reserve(size);
}

void String::Resize(int32 size)
{
    m_data.resize(size);
}

void String::Shrink()
{
    m_data.shrink_to_fit();
}

bool String::IsEmpty() const
{
    return m_data.empty();
}

bool String::IsNumeric() const
{
    return false;
}

bool String::IsValid(int64 index) const
{
    if (index<0 || index> m_data.size())
    {
        return false;
    }
    return true;
}

String String::Section(char sep, int section) const
{
    return Split(sep).At(section);
}

Array<String> String::Split(char sep) const
{
    Array<String> result;
    std::stringstream ss(m_data);
    std::string item;
    while (std::getline(ss, item, sep)) 
    {
        result.EmplaceBack(item);
    }
    return result;
}

String& String::Trim()
{
    m_data.erase(m_data.begin(), std::find_if(m_data.begin(), m_data.end(), [](char ch) { return !std::isspace(ch); }));
    m_data.erase(std::find_if(m_data.rbegin(), m_data.rend(),[](char ch) { return !std::isspace(ch); }).base(), m_data.end());
    return *this;
}

String& String::TrimLeft()
{
    m_data.erase(m_data.begin(), std::find_if(m_data.begin(), m_data.end(), [](int ch) { return !std::isspace(ch); }));
    return *this;
}

String& String::TrimRight()
{
    m_data.erase(std::find_if(m_data.rbegin(), m_data.rend(), [](int ch) { return !std::isspace(ch); }).base(), m_data.end());
    return *this;
}

void String::Swap(String& other)
{
    m_data.swap(other.m_data);
}

bool String::ToBool() const
{
    if (m_data == "true")
    {
        return true;
    }
    else if (m_data == "false")
    {
        return false;
    }
    else
    {
        throw std::invalid_argument("No digits were found");
    }
    
}

int8 String::ToInt8(int base) const
{
    int8 result;
    char* endptr;

    result = static_cast<int8>(std::strtol(m_data.c_str(), &endptr, base));

    // 检查转换是否成功
    if (endptr == m_data.c_str()) 
    {
        throw std::invalid_argument("No digits were found");
    }

    return result;
}

int16 String::ToInt16(int base) const
{
    int16 result;
    char* endptr;

    result = static_cast<int16>(std::strtol(m_data.c_str(), &endptr, base));

    // 检查转换是否成功
    if (endptr == m_data.c_str())
    {
        throw std::invalid_argument("No digits were found");
    }

    return result;
}

int32 String::ToInt32(int base) const
{
    int32 result;
    char* endptr;

    result = static_cast<int32>(std::strtol(m_data.c_str(), &endptr, base));

    // 检查转换是否成功
    if (endptr == m_data.c_str())
    {
        throw std::invalid_argument("No digits were found");
    }

    return result;
}

int64 String::ToInt64(int base) const
{
    int64 result;
    char* endptr;

    result = static_cast<int64>(std::strtol(m_data.c_str(), &endptr, base));

    // 检查转换是否成功
    if (endptr == m_data.c_str())
    {
        throw std::invalid_argument("No digits were found");
    }

    return result;
}

uint8 String::ToUInt8(int base) const
{
    uint8 result;
    char* endptr;

    result = static_cast<uint8>(std::strtoul(m_data.c_str(), &endptr, base));

    // 检查转换是否成功
    if (endptr == m_data.c_str())
    {
        throw std::invalid_argument("No digits were found");
    }

    return result;
}

uint16 String::ToUInt16(int base) const
{
    uint16 result;
    char* endptr;

    result = static_cast<uint16>(std::strtoul(m_data.c_str(), &endptr, base));

    // 检查转换是否成功
    if (endptr == m_data.c_str())
    {
        throw std::invalid_argument("No digits were found");
    }

    return result;
}

uint32 String::ToUInt32(int base) const
{
    uint32 result;
    char* endptr;

    result = static_cast<uint32>(std::strtoul(m_data.c_str(), &endptr, base));

    // 检查转换是否成功
    if (endptr == m_data.c_str())
    {
        throw std::invalid_argument("No digits were found");
    }

    return result;
}

uint64 String::ToUInt64(int base) const
{
    uint64 result;
    char* endptr;

    result = static_cast<uint64>(std::strtoul(m_data.c_str(), &endptr, base));

    // 检查转换是否成功
    if (endptr == m_data.c_str())
    {
        throw std::invalid_argument("No digits were found");
    }

    return result;
}

float String::ToFloat() const
{
    char* endptr;
    float result = std::strtof(m_data.c_str(), &endptr);

    // 检查转换是否成功
    if (endptr == m_data.c_str() || *endptr != '\0') 
    {
        throw std::invalid_argument("Invalid float conversion");
    }

    return result;
}
double String::ToDouble() const
{
    char* endptr;
    double result = std::strtod(m_data.c_str(), &endptr);

    // 检查转换是否成功
    if (endptr == m_data.c_str() || *endptr != '\0')
    {
        throw std::invalid_argument("Invalid float conversion");
    }

    return result;
}
std::string String::ToStdString() const
{
    return m_data;
}

const char* String::ToCString() const
{
    return m_data.c_str();
}

String& String::operator+=(const String& str)
{
    m_data += str.m_data;
    return *this;
}

/* friend */
//bool operator==(const String& left, const String& right)
//{
//    return left.m_data == right.m_data;
//}
//
//bool operator!=(const String& left, const String& right)
//{
//    return left.m_data != right.m_data;
//}
//
//bool operator>(const String& left, const String& right)
//{
//    return left.m_data > right.m_data;
//}
//
//bool operator>=(const String& left, const String& right)
//{
//    return left.m_data >= right.m_data;
//}
//
//bool operator<(const String& left, const String& right)
//{
//    return left.m_data < right.m_data;
//}
//
//bool operator<=(const String& left, const String& right)
//{
//    return left.m_data <= right.m_data;
//}

String operator+(const String& left, const String& right)
{
    String str(left);
    str.Resize(left.Size() + right.Size());
    str += right;
    return str;
}

//std::ostream& operator<<(std::ostream& os, String str)
//{
//    return os << str.ToStdString();
//}
}// namespace Star
