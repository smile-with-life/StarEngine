#pragma once

#include "StarEngine/Common/Core.h"

namespace Star {
class SE_API StarEngineLoop
{
public:
    StarEngineLoop() = default;
    ~StarEngineLoop() = default;
public:
    int PreInit();
    int Init();
    void Tick();
    void Exit();
    bool isRequestingExit();
private:
    bool m_requestingExit = false;// 请求退出标志
};
inline StarEngineLoop EngineLoop;
}// namespace Star


