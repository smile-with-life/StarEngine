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
    SharedPtr<T> AddComponent(Args... args)
    {
        SharedPtr<T> component = MakeShared<T>(args...);
        m_components.PushBack(component);
        return component;
    }

    template <class T>
    SharedPtr<T> GetComponent()
    {
       
      
    }

    template <class T>
    void RemoveComponent()
    {

    }

    void AddChild(SharedPtr<Entity> child);

    void RemoveChild(SharedPtr<Entity> child);

    void SetParent(Entity* parent);

    Entity* GetParent();
    
private:
    String m_name = "Undefined";   

    Array<SharedPtr<Component>> m_components;

    Entity* m_parent;

    Array<SharedPtr<Entity>> m_children;
};
}// namespace Star