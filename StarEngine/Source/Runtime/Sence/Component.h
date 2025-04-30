#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Object/Object.h"

namespace Star
{
class Component:public Object
{
public:
    Component();

    virtual ~Component();

};
}// namespace Star