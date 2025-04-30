#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
class SenceManager
{
public:
    void Init();

    void Tick();

    void Exit();
private:
    bool m_isLoadSence = false;
    String m_path; 
};
}// namespace Star