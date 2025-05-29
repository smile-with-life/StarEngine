#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Memory/ByteBuffer.h"
#include "Runtime/Core/Container/Array.h"

namespace Star
{
class String
{
public:
    using iterator = std::string::iterator;
    using const_iterator = std::string::const_iterator;
    using reverse_iterator = std::string::reverse_iterator;
    using const_reverse_iterator = std::string::const_reverse_iterator;
public:
    // 默认构造函数
    String() = default;

    // 析构函数
    ~String() = default;

    // 拷贝构造函数
    String(const String& other);

    // 拷贝赋值
    String& operator=(const String& other);

    // 移动构造函数
    String(String&& other);

    // 移动赋值
    String& operator=(String&& other);

    // C 风格字符串构造
    String(const char* str);

    // C 风格字符串赋值
    String& operator=(const char* str);

    // C++ 字符串构造
    String(const std::string& str);

    // C++ 字符串赋值
    String& operator=(const std::string& str);

    // 字节数组构造
    explicit String(const ByteArray& buffer);

    // 字节数组赋值
    String& operator=(const ByteArray& buffer);

    // 隐式转化为 std::string
    operator std::string() const;

    operator const std::string() const;

    operator const char* () const;
public:
    // 将 str 附加到字符串的末尾
    String& Append(const String& buffer);

    // 将 ch 附加到字符串的末尾
    String& Append(char ch);

    // 将 str 添加到字符串的开头
    String& Prepend(const String& str);

    // 将 ch 添加到字符串的开头
    String& Prepend(char ch);

    // 比较两个字符串
    int32 Compare(const String& str) const;

    // 判断字符串是否包含有给定的子串或字符 
    bool Contains(const String& str) const;

    // 返回给定子串或字符在字符串中首次出现的索引位置
    int32 IndexOf(const String& str) const;

    // 返回给定子串或字符在字符串中首次出现的索引位置
    int32 LastIndexOf(const String& str) const;

    // 判断字符串是否有给定前缀
    bool StartsWith(const String& str) const;

    // 判断字符串是否有给定后缀
    bool EndsWith(const String& str) const;

    // 向字符串中的指定位置插入
    String& Insert(int32 index, const String& str);

    // 替换字符串的指定部分
    String& Replace(int32 index, int32 n, const String& str);

    // 访问指定字符,有边界检查
    char& At(int32 index);

    // 访问指定字符
    char& operator[](int32 index);

    // 返回指定字符
    const char operator[](int32 index) const;

    // 访问字符串中的首个字符
    char& FrontChar();

    // 返回字符串中的首个字符
    const char FrontChar() const;

    // 访问字符串中的最后一个字符
    char& BackChar();

    // 返回字符串中的最后一个字符
    const char BackChar() const;

    // 从字符串起始移除 n 个字符
    String& ChopLeft(int32 n);

    // 从字符串中间移除 n 个字符
    String& ChopMid(int32 index, int32 n);

    // 从字符串末尾移除 n 个字符
    String& ChopRight(int32 n);

    // 保留字符串最左侧的 n 个字符,其余部分舍弃掉
    String& RemianLeft(int32 n);

    // 保留字符串从 index 位置开始的 n 个字符,其余部分舍弃掉
    String& RemianMid(int32 index, int32 n);

    // 保留字符串最右侧的 n 个字符,其余部分舍弃掉
    String& RemianRight(int32 n);

    // 返回一个字符串最左侧的 n 个字符的子串
    String LeftStr(int32 n);

    // 返回一个字符串从 index 位置开始的 n 个字符的子串
    String MidStr(int32 index, int32 n);

    // 返回一个字符串从 (start, end) 的子串,不包括 start 和 end
    String SubStr(int64 start, int64 end);

    // 返回一个字符串最右侧的 n 个字符的子串
    String RightStr(int32 n);

    // 返回一个从开始字符到结束字符的字符串
    String Match(char start, char end);

    // 清空字符串
    void Clear();

    // 返回字符串预分配空间的大小
    int32 Capacity() const;
    
    // 返回字符串的大小
    int32 Size() const;

    // 预分配内存大小
    void Reserve(int32 size);

    // 改变存储元素的个数
    void Resize(int32 size);
   
    // 移除未使用的容量
    void Shrink();
    
    // 判断字符串是否为空
    bool IsEmpty() const;

    // 判断字符串是否仅包含数字字符
    bool IsNumeric() const;

    // 判断索引是否为有效值
    bool IsValid(int64 index) const;

    // 返回以 sep 分割符分割的字符串中的指定部分
    String Section(char sep, int section) const;

    // 返回以 sep 分割符分割的字符串中的所有部分
    Array<String> Split(char sep) const;

    // 移除字符串左右两侧的空白字符
    String& Trim();

    // 移除字符串左侧的空白字符
    String& TrimLeft();

    // 移除字符串右侧的空白字符
    String& TrimRight();
      
    // 交换两个字符串
    void Swap(String& other);

    // 将字符串转换为 int8 类型的值
    bool ToBool() const;

    // 将字符串转换为 int8 类型的值
    int8 ToInt8(int base = 10) const;

    // 将字符串转换为 int16 类型的值
    int16 ToInt16(int base = 10) const;

    // 将字符串转换为 int32 类型的值
    int32 ToInt32(int base = 10) const;

    // 将字符串转换为 int64 类型的值
    int64 ToInt64(int base = 10) const;

    // 将字符串转换为 uint8 类型的值
    uint8 ToUInt8(int base = 10) const;

    // 将字符串转换为 uint16 类型的值
    uint16 ToUInt16(int base = 10) const;

    // 将字符串转换为 uint32 类型的值
    uint32 ToUInt32(int base = 10) const;

    // 将字符串转换为 uint64 类型的值
    uint64 ToUInt64(int base = 10) const;

    // 将字符串转换为 float 类型的值
    float ToFloat() const;

    // 将字符串转换为 double 类型的值
    double ToDouble() const;

    // 将字符串转换为 C++ 类型的字符串
    std::string ToStdString() const;
    
    // 将字符串转换为 C 类型的字符串
    const char* ToCString() const;
public:
    String& operator+=(const String& str);

    String& operator+=(char ch);

    friend String operator+(const String& left, const String& right);

    friend bool operator==(const String& left, const String& right);

    friend bool operator==(const String& left, const char* right);

    friend bool operator==(const char* left, const String& right);

    friend bool operator!=(const String& left, const String& right);

    friend bool operator!=(const String& left, const char* right);

    friend bool operator!=(const char* left, const String& right);

    friend bool operator>(const String& left, const String& right);

    friend bool operator>(const String& left, const char* right);

    friend bool operator>(const char* left, const String& right);

    friend bool operator>=(const String& left, const String& right);

    friend bool operator>=(const String& left, const char* right);

    friend bool operator>=(const char* left, const String& right);

    friend bool operator<(const String& left, const String& right);

    friend bool operator<(const String& left, const char* right);

    friend bool operator<(const char* left, const String& right);

    friend bool operator<=(const String& left, const String& right);

    friend bool operator<=(const String& left, const char* right);

    friend bool operator<=(const char* left, const String& right);

    friend std::ostream& operator<<(std::ostream& os, const String& str);
public:
    [[nodiscard]] constexpr iterator begin() noexcept
    {
        return m_data.begin();
    }

    [[nodiscard]] constexpr const_iterator begin() const noexcept
    {
        return m_data.begin();
    }

    [[nodiscard]] constexpr iterator end() noexcept
    {
        return m_data.end();
    }

    [[nodiscard]] constexpr const_iterator end() const noexcept
    {
        return m_data.end();
    }

    [[nodiscard]] constexpr const_iterator cbegin() const noexcept
    {
        return m_data.cbegin();
    }

    [[nodiscard]] constexpr const_iterator cend() const noexcept
    {
        return m_data.cend();
    }

    [[nodiscard]] constexpr reverse_iterator rbegin() noexcept
    {
        return m_data.rbegin();
    }

    [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept
    {
        return m_data.rbegin();
    }

    [[nodiscard]] constexpr reverse_iterator rend() noexcept
    {
        return m_data.rend();
    }

    [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept
    {
        return m_data.rend();
    }

    [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept
    {
        return m_data.crbegin();
    }

    [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept
    {
        return m_data.crend();
    }
public:
    static String FromStdString(const std::string& str);
    static String FromCString(const char* str);
    static String FromInt8(int8 value);
    static String FromInt16(int16 value);
    static String FromInt32(int32 value);
    static String FromInt64(int64 value);
    static String FromUInt8(uint8 value);
    static String FromUInt16(uint16 value);
    static String FromUInt32(uint32 value);
    static String FromUInt64(uint64 value);
    static String FromFloat(float value);
    static String FromDouble(double value);
    static String FromBool(bool value);
private:
    // UTF-8 字符串
    std::string m_data;
};
using Name = String;
}// namespace Star