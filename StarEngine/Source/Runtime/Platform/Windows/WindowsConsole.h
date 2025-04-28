#pragma once

#include "Runtime/Core/Core.h"

#include "Runtime/Platform/Console.h"

namespace Star
{

class WindowsConsole:public Console
{
public:
    WindowsConsole();

    virtual ~WindowsConsole();

    virtual void Init() override;

    virtual void Tick() override;

    virtual void Exit() override;
private:
    // 控制台句柄
    HANDLE m_console;
};

}// namespace Star