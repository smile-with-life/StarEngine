#include "starpch.h"
#include "Json.h"

namespace Star
{
/* member */
Json::Json(std::nullptr_t) noexcept
    : m_type(JsonType::Null)
    , m_value(std::monostate{})
{

}

Json::Json(bool value)
    : m_type(JsonType::Bool)
    , m_value(value)
{
}

Json::Json(int32 value)
    : m_type(JsonType::Int)
    , m_value(value)
{

}

Json::Json(double value)
    : m_type(JsonType::Float)
    , m_value(value)
{

}

Json::Json(const string& value)
    : m_type(JsonType::String)
    , m_value(value)
{

}

Json::Json(const char* value)
    : m_type(JsonType::String)
    , m_value(String(value))
{

}

Json::Json(const array& value)
    : m_type(JsonType::Array)
    , m_value(value)
{

}

Json::Json(const object& value)
    : m_type(JsonType::Object)
    , m_value(value)
{

}

Json::Json(JsonType type)
    : m_type(type)
{
    switch (type)
    {
    case JsonType::Null:
        m_value = std::monostate{};
        break;
    case JsonType::Bool:
        m_value = false;
        break;
    case JsonType::Int:
        m_value = 0;
        break;
    case JsonType::Float:
        m_value = 0.0;
        break;
    case JsonType::String:
        m_value = String{};
        break;
    case JsonType::Array:
        m_value = JsonArray{};
        break;
    case JsonType::Object:
        m_value = JsonObject{};
        break;
    }
}

bool Json::IsNull() const noexcept
{
    return m_type == JsonType::Null;
}

bool Json::IsBool() const noexcept
{
    return m_type == JsonType::Bool;
}

bool Json::IsInt() const noexcept
{
    return m_type == JsonType::Int;
}

bool Json::IsFloat() const noexcept
{
    return m_type == JsonType::Float;
}

bool Json::IsString() const noexcept
{
    return m_type == JsonType::String;
}

bool Json::IsArray() const noexcept
{
    return m_type == JsonType::Array;
}

bool Json::IsObject() const noexcept
{
    return m_type == JsonType::Object;
}

JsonType Json::Type() const
{
    return JsonType();
}

void Json::Append(const Json& json)
{
    if (IsArray())
    {
        // Get the array reference
        array& arr = std::get<array>(m_value);
        // Append the new Json object to the array
        arr.PushBack(json);
    }
    else
    {
        // Handle the case where the Json is not an array
        throw std::runtime_error("Cannot append to a non-array Json object");
    }
}

bool Json::Contains(const string& key) const
{
    // Check if the current Json is an object
    if (IsObject())
    {
        // Get the object reference
        const object& obj = std::get<object>(m_value);
        // Check if the key exists in the object
        return obj.Contains(key);
    }
    else
    {
        // Handle the case where the Json is not an object
        throw std::runtime_error("Cannot check key in a non-object Json object");
    }
}

void Json::Erase(const string& key)
{
    // Check if the current Json is an object
    if (IsObject())
    {
        // Get the object reference
        object& obj = std::get<object>(m_value);
        // Erase the key from the object
        obj.Erase(key);
    }
    else
    {
        // Handle the case where the Json is not an object
        throw std::runtime_error("Cannot erase key from a non-object Json object");
    }
}

String Json::Serialize() const
{
    std::ostringstream ss;
    SerializeHelper(ss, *this);
    return String(ss.str());
}

String Json::ToString() const
{
    return Serialize();
}

Json::operator bool()
{
    return Get<bool>();
}

Json::operator int32()
{
    return Get<int32>();
}

Json::operator double()
{
    return Get<double>();
}

Json::operator string()
{
    return Get<String>();
}

Json::operator array()
{
    return Get<JsonArray>();
}

Json::operator object()
{
    return Get<JsonObject>();
}

std::ostream& operator<<(std::ostream& os, const Json& json)
{
    return os << json.Serialize();
}

Json& Json::operator[](int32 index)
{
    if (!IsArray()) 
    {
        throw std::runtime_error("JSON type mismatch: expected array");
    }
    auto& arr = Get<JsonArray>();
    if (index < 0 || index >= static_cast<int32>(arr.Size())) 
    {
        throw std::out_of_range("Array index out of bounds");
    }
    return arr[index];
}

const Json& Json::operator[](int32 index) const
{
    if (!IsArray())
    {
        throw std::runtime_error("JSON type mismatch: expected array");
    }
    auto& arr = Get<JsonArray>();
    if (index < 0 || index >= static_cast<int32>(arr.Size()))
    {
        throw std::out_of_range("Array index out of bounds");
    }
    return arr[index];
}

Json& Json::operator[](const string& key)
{
    if (!IsObject()) 
    {
        throw std::runtime_error("JSON type mismatch: expected object");
    }
    auto& obj = Get<JsonObject>();
    return obj[key];
}

const Json& Json::operator[](const string& key) const
{
    if (!IsObject())
    {
        throw std::runtime_error("JSON type mismatch: expected object");
    }
    auto& obj = Get<JsonObject>();
    return obj.At(key);
}

Json& Json::operator[](const char* key)
{
    if (!IsObject())
    {
        throw std::runtime_error("JSON type mismatch: expected object");
    }
    auto& obj = Get<JsonObject>();
    return obj[key];
}

const Json& Json::operator[](const char* key) const
{
    if (!IsObject())
    {
        throw std::runtime_error("JSON type mismatch: expected object");
    }
    auto& obj = Get<JsonObject>();
    return obj.At(key);
}

Json& Json::operator=(std::nullptr_t) noexcept
{
    m_type = JsonType::Null;
    m_value = std::monostate{};
    return *this;
}

Json& Json::operator=(bool value) noexcept
{
    m_type = JsonType::Bool;
    m_value = value;
    return *this;
}

Json& Json::operator=(int value) noexcept
{
    m_type = JsonType::Int;
    m_value = static_cast<int32>(value);
    return *this;
}

Json& Json::operator=(double value) noexcept
{
    m_type = JsonType::Float;
    m_value = value;
    return *this;
}

Json& Json::operator=(const string& value) noexcept
{
    m_type = JsonType::String;
    m_value = value;
    return *this;
}

Json& Json::operator=(const array& value) noexcept
{
    m_type = JsonType::Array;
    m_value = value;
    return *this;
}

Json& Json::operator=(const object& value) noexcept
{
    m_type = JsonType::Object;
    m_value = value;
    return *this;
}

bool operator==(const Json& left, const Json& right)
{
    if (left.m_type != right.m_type) {
        return false;
    }

    return std::visit([](auto&& leftValue, auto&& rightValue) -> bool {
        using LeftType = std::decay_t<decltype(leftValue)>;
        using RightType = std::decay_t<decltype(rightValue)>;

        if constexpr (std::is_same_v<LeftType, RightType>) 
        {
            if constexpr (std::is_same_v<LeftType, std::monostate>)
            {
                return true; // 两个都是null
            }
            else 
            {
                return leftValue == rightValue;
            }
        }
        else
        {
            return false;
        }
        }, left.m_value, right.m_value);
}

bool operator!=(const Json& left, const Json& right)
{
    return !(left == right);
}

void Json::SerializeHelper(std::ostream& os, const Json& json) const
{
    switch (json.m_type) {
    case JsonType::Null:
        os << "null";
        break;
    case JsonType::Bool:
        os << (json.Get<bool>() ? "true" : "false");
        break;
    case JsonType::Int:
        os << json.Get<int32>();
        break;
    case JsonType::Float:
        os << json.Get<double>();
        break;
    case JsonType::String: {
        String str = json.Get<String>();
        os << "\"";
        for (char ch : str) 
        {
            switch (ch) 
            {
            case '\"': 
            {
                os << "\\\"";
                break;
            }
            case '\\': 
            {
                os << "\\\\"; break;
            }
            case '/':  
            {
                os << "\\/";  break;
            }
            case '\b': 
            {
                os << "\\b";  break;
            }
            case '\f': 
            {
                os << "\\f";  break;
            }
            case '\n': 
            {
                os << "\\n";  break;
            }
            case '\r': 
            {
                os << "\\r";  break;
            }
            case '\t': 
            {
                os << "\\t";  break;
            }
            default:
            {
                if (ch >= 0 && ch <= 0x1f)
                {
                    os << "\\u" << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(ch);
                }
                else 
                {
                    os << ch;
                }
            }
            }// switch
        }
        os << "\"";
        break;
    }
    case JsonType::Array: 
    {
        const auto& arr = json.Get<array>();
        os << "[";
        for (int32 i = 0; i < arr.Size(); ++i) 
        {
            if (i != 0) 
            {
                os << ",";
            }
            SerializeHelper(os, arr[i]);
        }
        os << "]";
        break;
    }
    case JsonType::Object: 
    {
        const auto& obj = json.Get<object>();
        os << "{";
        bool first = true;
        for (const auto& [key, value] : obj) 
        {
            if (!first) os << ",";
            os << "\"" << key << "\":";
            SerializeHelper(os, value);
            first = false;
        }
        os << "}";
        break;
    }
    default:
        throw std::runtime_error("Unknown JSON type");
    }// switch
}

void Json::SkipWhitespace(const char*& ptr)
{
    while (*ptr && std::isspace(*ptr)) 
    {
        ++ptr;
    }
}

/* static */
String Json::ParseString(const char*& ptr)
{
    ++ptr; // 跳过开始的引号
    String result;
    while (*ptr && *ptr != '"') 
    {
        if (*ptr == '\\') 
        {
            ++ptr; // 跳过转义字符
            switch (*ptr) 
            {
            case '"': 
                result += '"'; 
                break;
            case '\\': 
                result += '\\'; 
                break;
            case '/': 
                result += '/'; 
                break;
            case 'b': 
                result += '\b'; 
                break;
            case 'f': 
                result += '\f'; 
                break;
            case 'n': 
                result += '\n'; 
                break;
            case 'r': 
                result += '\r'; 
                break;
            case 't': 
                result += '\t'; 
                break;
                // 可以添加更多转义序列处理
            default:
                throw std::runtime_error("Invalid escape sequence");
            }
        }
        else 
        {
            result += *ptr;
        }
        ++ptr;
    }
    if (*ptr != '"') 
    {
        throw std::runtime_error("Unterminated string");
    }
    ++ptr; // 跳过结束的引号
    return result;
}

Json Json::ParseNumber(const char*& ptr)
{
    String str;
    bool isFloat = false;

    while (*ptr && (std::isdigit(*ptr) || *ptr == '.' || *ptr == '-' || *ptr == 'e' || *ptr == 'E' || *ptr == '+'))
    {
        if (*ptr == '.') isFloat = true;
        str += *ptr;
        ++ptr;
    }


    if (isFloat) 
    {
        return Json(str.ToDouble());
    }
    else 
    {
        return Json(str.ToInt32());
    }
}

Json Json::ParseValue(const char*& ptr)
{
    SkipWhitespace(ptr);

    if (*ptr == '{') 
    {
        // 解析对象
        ++ptr;
        Json obj(JsonType::Object);
        SkipWhitespace(ptr);

        while (*ptr && *ptr != '}') 
        {
            // 解析键
            String key = ParseString(ptr);

            SkipWhitespace(ptr);
            if (*ptr != ':')
            {
                throw std::runtime_error("Expected ':' after key");
            }
            ++ptr;
            SkipWhitespace(ptr);

            // 解析值
            Json value = ParseValue(ptr);

            // 将键值对添加到对象中
            obj[key] = value;

            SkipWhitespace(ptr);
            if (*ptr == ',') 
            {
                ++ptr;
                SkipWhitespace(ptr);
            }
        }

        if (*ptr != '}') 
        {
            throw std::runtime_error("Expected '}' to end object");
        }
        ++ptr;
        return obj;
    }
    else if (*ptr == '[') 
    {
        // 解析数组
        ++ptr;
        Json arr(JsonType::Array);
        SkipWhitespace(ptr);

        while (*ptr && *ptr != ']') 
        {
            // 解析数组元素
            Json element = ParseValue(ptr);
            arr.Append(element);

            SkipWhitespace(ptr);
            if (*ptr == ',')
            {
                ++ptr;
                SkipWhitespace(ptr);
            }
        }

        if (*ptr != ']') 
        {
            throw std::runtime_error("Expected ']' to end array");
        }
        ++ptr;
        return arr;
    }
    else if (*ptr == '"') 
    {
        // 解析字符串
        return Json(ParseString(ptr));
    }
    else if (*ptr == 't' || *ptr == 'f') 
    {
        // 解析布尔值
        bool value = (*ptr == 't');
        if (std::strncmp(ptr, "true", 4) == 0) 
        {
            ptr += 4;
        }
        else if (std::strncmp(ptr, "false", 5) == 0)
        {
            ptr += 5;
            value = false;
        }
        else 
        {
            throw std::runtime_error("Invalid boolean value");
        }
        return Json(value);
    }
    else if (*ptr == 'n') 
    {
        // 解析null
        if (std::strncmp(ptr, "null", 4) == 0) 
        {
            ptr += 4;
            return Json(nullptr);
        }
        else 
        {
            throw std::runtime_error("Invalid null value");
        }
    }
    else if (std::isdigit(*ptr) || *ptr == '-') 
    {
        // 解析数字
        return ParseNumber(ptr);
    }
    else 
    {
        throw std::runtime_error("Unexpected character in JSON");
    }
}

Json Json::Parse(const string& jsonString)
{
    const char* ptr = jsonString.ToCString();
    Json result = ParseValue(ptr);
    SkipWhitespace(ptr);
    if (*ptr != '\0') 
    {
        throw std::runtime_error("Extra characters after JSON value");
    }
    return result;
}

Json Json::Array()
{
    return Json(JsonType::Array);
}

Json Json::Object()
{
    return Json(JsonType::Object);
}
}// namespace Star