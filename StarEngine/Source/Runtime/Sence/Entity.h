#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Object/Object.h"
#include "Runtime/Core/Container/List.h"
#include "Runtime/Sence/Component.h"

namespace Star
{
class Entity:public Object
{
public:
    Entity();

    virtual ~Entity();
private:
    String m_name;
    Entity* m_parent;
    List<Entity*> m_childrens;
    List<Component*> m_components;
};
}// namespace Star