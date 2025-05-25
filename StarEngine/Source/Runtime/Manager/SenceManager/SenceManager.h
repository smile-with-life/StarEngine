#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"
#include "Runtime/Core/Container/Map.h"
#include "Runtime/Core/GUID/GUID.h"
#include "Runtime/Sence/Sence.h"

namespace Star
{
class SenceManager
{
public:
    SenceManager() = default;
public:
    void Init();

    void Tick();

    void Exit();

    void LoadSence(const String& senceUrl);
private:
    // 场景列表
    Array<Shared<Sence>> m_sences;

    // 当前活动的场景
    Shared<Sence> m_activeSence;
};
}// namespace Star