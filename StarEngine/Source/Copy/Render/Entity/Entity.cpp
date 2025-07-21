#include "starpch.h"
#include "Entity.h"

namespace Star
{


Entity::~Entity()
{

}

void Entity::Init()
{

}

void Entity::Tick()
{
    for (auto& component : m_components)
    {
        if (component->isActive)
        {
            component->Tick();
        }
    }
}

void Entity::Exit()
{

}
}// namespace Star