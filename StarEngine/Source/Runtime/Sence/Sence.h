#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Object/Object.h"
#include "Runtime/Core/GUID/GUID.h"
#include "Runtime/Core/Container/Map.h"
#include "Runtime/Sence/Entity.h"

namespace Star
{
class Sence :public Object
{
public:
    void Init();

    void Tick();

    void Render();

    void Exit();
public:
    Map<GUID, Entity> m_entitys;
};
}// namespace Star