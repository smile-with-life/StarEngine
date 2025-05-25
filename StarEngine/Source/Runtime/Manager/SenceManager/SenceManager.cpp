#include "starpch.h"
#include "SenceManager.h"

namespace Star
{
void SenceManager::Init()
{
    m_sences.EmplaceBack(MakeShared<Sence>("Main Sence"));
    m_currentSence = m_sences[0];
}

void SenceManager::Tick()
{
    // 找到当前活动的场景
    m_currentSence->Tick();
}

void SenceManager::Exit()
{

}

void SenceManager::LoadSence(const String& senceUrl)
{
    Shared<Sence> sence = MakeShared<Sence>();    
    m_activeSence = sence;

    const bool is_level_load_success = sence->Load(senceUrl);
    if (is_level_load_success == false)
    {
        return false;
    }

    m_loaded_levels.emplace(level_url, level);

    return true;
}
}// namespace Star