#include "starpch.h"
#include "SenceManager.h"

namespace Star
{
void SenceManager::Init()
{
    /*m_sences.EmplaceBack(MakeShared<Sence>("Main Sence"));
    m_activeSence = m_sences[0];*/
}

void SenceManager::Tick()
{
    // 找到当前活动的场景
    //m_activeSence->Tick();
}

void SenceManager::Exit()
{

}

void SenceManager::LoadWorld(const String& worldUrl)
{
    m_world.Load(worldUrl);

    LoadSence(m_world.defaultSenceUrl);
}

void SenceManager::LoadSence(const String& senceUrl)
{
    SharedPtr<Sence> sence = MakeShared<Sence>();
    m_activeSence = sence;
    m_activeSence->Load(senceUrl);
}
}// namespace Star