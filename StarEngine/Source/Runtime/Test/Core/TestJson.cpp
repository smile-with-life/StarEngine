#include "starpch.h"
#include "Runtime/Test/Test.h"
#include "Runtime/Core/File/File.h"
#include "Runtime/Core/Json/Json.h"
#include "Runtime/Core/String/String.h"

namespace Star::Test
{
void Test_Json()
{
    String jsonObjectString = R"(
        {
            "str":"字符串",
            "num":1,
            "float": 3.0,
            "object":{"value1":"objectName","value2":{"sub":2}},
            "array":[1,2,3,4,5]
        }
    )"; 
    String jsonArrayString = R"(
        [
            {
                "str":"字符串",
                "num":1,
                "float": 3.0,
                "object":{"value1":"objectName","value2":{"sub":2}},
                "array":[1,2,3,4,5]
            },
            {
                "str":"123"
            }
        ]
    )";

    Json json1 = Json::Parse(jsonObjectString);
    std::cout << "str:" << json1["str"] << std::endl;
    std::cout << "num:" << json1["num"] << std::endl;
    std::cout << "float:" << json1["float"] << std::endl;
    std::cout << "object:" << json1["object"] << std::endl;
    std::cout << "array:" << json1["array"] << std::endl;

    Json json2 = Json::Parse(jsonArrayString);
    std::cout << "obj1:" << json2[0] << std::endl;
    std::cout << "obj2:" << json2[1] << std::endl;


    Json json3 = nullptr;
    std::cout << json3 << std::endl;

    Json json4 = true;
    bool v1 = json4;
    std::cout << json4 << std::endl;
    std::cout << json4.Get<bool>() << std::endl;

    Json json5 = 123;
    int v2 = json5;
    std::cout << json5 << std::endl;
    std::cout << json5.Get<int32>() << std::endl;

    Json json6 = 3.14;
    double v3 = json6;
    std::cout << json6 << std::endl;
    std::cout << json6.Get<double>() << std::endl;

    Json json7 = "test string";
    String v4 = json7;
    std::cout << json7 << std::endl;
    std::cout << json7.Get<String>() << std::endl;

    Json json8 = Json::Array();
    JsonArray v5 = json8;
    std::cout << json8 << std::endl;
    std::cout << json8.Get<JsonArray>() << std::endl;

    Json json9 = Json::Object();
    JsonObject v6 = json9;
    std::cout << json9 << std::endl;
    std::cout << json9.Get<JsonObject>() << std::endl;

    Json json10(JsonType::Null);
    std::cout << json10 << std::endl;

    //Json json11;
    //json11 = false;
    //json11 = 3;
    //json11 = 1.11;
    //json11 = "qwe";
    ///*json11 = { 1,2,3 };
    //json11 = { {"v1",1},{"v2",2} }; */ 

    //Json json12;
    //json12["13"];
    //json12[2];
}
}