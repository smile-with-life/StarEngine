#include "starpch.h"
#include "Json.h"

namespace Star
{
Json::Json(int64 value)
    : nlohmann::json(value)
{

}

Json::Json(double value)
    : nlohmann::json(value)
{

}

Json::Json(bool value)
    : nlohmann::json(value)
{

}

Json::Json(const String& value)
    : nlohmann::json(value)
{

}

Json::Json(std::initializer_list<std::pair<const std::string, Json>> ilist)
    : nlohmann::json(ilist)
{
    
}

Json::Json(std::initializer_list<Json> ilist)
    : nlohmann::json(ilist)
{

}
}// namespace Star