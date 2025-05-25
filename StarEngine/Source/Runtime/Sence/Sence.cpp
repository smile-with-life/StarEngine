#include "starpch.h"
#include "Sence.h"

namespace Star
{
void Sence::Init()
{
    
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
}

void Sence::Load(const String& senceUrl)
{
    
}
}// namespace Star