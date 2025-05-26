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
    Json json1 = Json::Parse(jsonObjectString.ToStdString());
    std::cout << "str:" << json1.At("str") << std::endl;
    std::cout << "num:" << json1.At("num") << std::endl;
    std::cout << "float:" << json1.At("float") << std::endl;
    std::cout << "object:" << json1.At("object") << std::endl;
    std::cout << "array:" << json1.At("array") << std::endl;
    
    Json json2;
    json2["pi"] = 3.14;
    json2["happy"] = true;

    std::cout << json2 << std::endl;

    Json json3 = Json::Parse(jsonArrayString.ToStdString());;
    std::cout << "obj1:" << json3[0] << std::endl;
    std::cout << "obj2:" << json3[1] << std::endl;

    std::cout << json3 << std::endl;

    Json json4 = "123";
    std::cout << json4 << std::endl;

    Json json5 = 1;
    std::cout << json5 << std::endl;

    Json json6 = 3.0;
    std::cout << json6 << std::endl;

    Json json7 = { {"value",1}};
    std::cout << json7 << std::endl;

    Json json8 = {1,2,3};
    std::cout << json8 << std::endl;

    Json json9;
    std::cout << json9 << std::endl;
    
    
}
}