#include "starpch.h"
#include "Sence.h"

namespace Star
{
void Sence::Init()
{
    for (auto& entity : m_entities)
    {
        entity.Init();
    }
}

void Sence::Tick()
{
    for (auto& entity : m_entities)
    {     
        entity.Tick();
    }
}

void Sence::Exit()
{
    for (auto& entity : m_entities)
    {
        entity.Exit();
    }
}

void Sence::Load(const String& senceUrl)
{
    
}
}// namespace Star