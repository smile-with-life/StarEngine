#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"
#include <nlohmann/json.h>

namespace Star
{
class Json:public nlohmann::json
{
public:
    Json() = default;

    ~Json() = default;

    Json(const Json& other) = default;

    Json& operator=(const Json& other) = default;

    Json(Json&& other) = default;

    Json& operator=(Json&& other) = default;

    Json(int64 value);

    Json(double value);

    Json(bool value);

    Json(const String& value);

    // 初始化列表构造对象（如 {{"key": value}}）
    Json(std::initializer_list<std::pair<const std::string, Json>> ilist);

    // 初始化列表构造数组（如 {1,2,3}）
    Json(std::initializer_list<Json> ilist);
public:
    Json& At(const String& key) 
    {
        return *static_cast<Json*>(&this->at(key.ToStdString()));
    }

    const Json& At(const String& key) const
    {
        return *static_cast<const Json*>(&this->at(key.ToStdString()));
    }

    Json& Front()
    {
        return *static_cast<Json*>(&this->front());
    }

    const Json& Front() const
    {
        return *static_cast<const Json*>(&this->front());
    }

    Json& Back()
    {
        return *static_cast<Json*>(&this->back());
    }

    const Json& Back() const
    {
        return *static_cast<const Json*>(&this->back());
    }

    void Clear()
    {
        this->clear();
    }

    bool Contains(const String& key) const
    {
        return this->contains(key.ToStdString());
    }

    int32 Count(const String& key) const
    {
        return this->count(key.ToStdString());
    }

    template<class... Args>
    std::pair<iterator, bool> Emplace(Args&& ... args)
    {
        return this->emplace(std::forward<Args>(args)...);
    }

    template<class... Args>
    std::pair<iterator, bool> EmplaceBack(Args&& ... args)
    {
        return this->emplace_back(std::forward<Args>(args)...);
    }

    iterator Erase(iterator pos)
    {
        return this->erase(pos);
    }

    const_iterator Erase(const_iterator pos)
    {
        return this->erase(pos);
    }


    iterator Erase(iterator first, iterator last)
    {
        return this->erase(first, last);
    }

    const_iterator Erase(const_iterator first, const_iterator last)
    {
        return this->erase(first, last);
    }

    int32 Erase(const String& key)
    {
        return this->erase(key.ToStdString());
    }

    iterator Find(const String& key)
    {
        return this->find(key.ToStdString());
    }

    const_iterator Find(const String& key) const
    {
        return this->find(key.ToStdString());
    }

    template<class T>
    T Get() const
    {
        return this->get<T>();
    }

    iterator Insert(const_iterator pos, const basic_json& value)
    {
        return this->insert(pos, value);
    }

    iterator Insert(const_iterator pos, basic_json&& value)
    {
        return this->insert(pos, std::move(value));
    }

    iterator Insert(const_iterator pos, size_type count, const basic_json& value)
    {
        return this->insert(pos, count, value);
    }

    iterator Insert(const_iterator pos, const_iterator first, const_iterator last)
    {
        return this->insert(pos, first, last);
    }

    iterator Insert(const_iterator pos, initializer_list_t ilist)
    {
        return this->insert(pos, ilist);
    }

    void Insert(const_iterator first, const_iterator last)
    {
        return this->insert(first, last);
    }

    bool IsString() const
    {
        return this->is_string();
    }

    bool IsInt() const
    {
        return this->is_number_integer();
    }

    bool IsFloat() const
    {
        return this->is_number_float();
    }

    bool IsBool() const
    {
        return this->is_boolean();
    }

    bool IsArray() const
    {
        return this->is_array();
    }

    bool IsObject() const
    {
        return this->is_object();
    }

    bool IsNull() const
    {
        return this->is_null();
    }

public:
    Json& operator[](const std::string& key) 
    {
        return *static_cast<Json*>(&(*this)[key]);
    }

    const Json& operator[](const std::string& key) const
    {
        return *static_cast<const Json*>(&(*this)[key]);
    }
public:
    static Json Parse(const String& jsonString)
    {
        return nlohmann::json::parse(jsonString.ToStdString());
    }

    static Json Object()
    {
        return nlohmann::json::object();
    }

    static Json Array()
    {
        return nlohmann::json::object();
    }
private:
    Json(const nlohmann::json& json)
        : nlohmann::json(json)
    {

    }
};

//template<>
//inline String Json::GetValue(const String& key) const
//{
//    return m_json.at(key.ToStdString()).get<std::string>();
//}
}// namespace Star

namespace nlohmann {
    template<>
    struct adl_serializer<Star::String> {
        // 序列化：String -> json
        static void to_json(json& json, const Star::String& str) 
        {
            json = str.ToStdString();
        }

        // 反序列化：json -> String
        static void from_json(const json& json, Star::String& str)
        {
            if (!json.is_string())
            {
                throw json::type_error::create(302, "类型必须为字符串", &json);
            }
            str = json.get<std::string>();
        }
    };
}