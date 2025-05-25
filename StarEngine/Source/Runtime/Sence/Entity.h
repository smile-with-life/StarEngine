#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Object/Object.h"
#include "Runtime/Core/Container/List.h"
#include "Runtime/Sence/Component.h"
#include "Runtime/Core/String/String.h"
#include "Runtime/Core/Memory/RAII.h"

namespace Star
{
class Entity:public Object
{
public:
    Entity() = default;

    virtual ~Entity();

    Entity(const Entity& other) = default;

    Entity& operator=(const Entity& other) = default;

    Entity(Entity&& other) = default;

    Entity& operator=(Entity&& other) = default;

    Entity(String name)
        : m_name(name)
    {


    }  
public:
    void Init();

    void Tick();

    void Exit();

    template <class T, class... Args> 
    Shared<T> AddComponent(Args... args)
    {
        Shared<T> component = MakeShared<T>(args...);       
        m_components.PushBack(component);
        return component;
    }
private:
    String m_name = "Undefined";

    Array<Shared<Component>> m_components;
};
}// namespace Star