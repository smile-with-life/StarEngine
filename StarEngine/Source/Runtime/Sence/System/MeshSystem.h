#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Sence/System.h"

namespace Star
{
class MeshSystem :public System
{
public:
    virtual void Init();

    virtual void Tick();

    virtual void Exit();
private:

};
}// namespace Star