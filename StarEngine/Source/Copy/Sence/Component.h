#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Object/Object.h"

namespace Star
{
class Entity;
class Component:public Object
{
public:
    Component();

    virtual ~Component();
public:
    virtual void Init();
    virtual void Tick();
    virtual void Exit();
public:
    Entity* entity = nullptr;
    String type = "None";
    bool isActive = true;
};
}// namespace Star