#pragma once

#include "Runtime/Core/Core.h"

namespace Star
{
class TemplateClass
{
public:
    // 默认构造函数
    TemplateClass() = default;
    // 析构函数
    ~TemplateClass() = default;
    // 拷贝构造函数
    TemplateClass(const TemplateClass& other) = default;
    // 拷贝赋值函数
    TemplateClass& operator=(const TemplateClass& other) = default;
    // 移动构造函数
    TemplateClass(TemplateClass&& other) = default;
    // 移动赋值函数
    TemplateClass& operator=(TemplateClass&& other) = default;
private:

};
}// namespace Star