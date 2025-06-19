#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/Object/Object.h"
#include "Runtime/Core/GUID/GUID.h"
#include "Runtime/Core/Container/Map.h"
#include "Runtime/Render/Entity/Entity.h"
#include "Runtime/Sence/System/MeshSystem.h"

namespace Star
{
class Sence :public Object
{
public:
    Sence() = default;

    Sence(String name)
        : m_name(name)
    {
        
    }
public:
    void Init();

    void Tick();

    void Exit();

    void Load(const String& senceUrl);
public:
    // 场景名称
    String m_name = "Undefined";

    // 实体列表
    Array<Entity> m_entities;
};
}// namespace Star