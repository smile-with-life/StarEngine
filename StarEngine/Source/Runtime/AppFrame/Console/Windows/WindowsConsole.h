#pragma once

#include "Runtime/Core/Core.h"

#include "Runtime/AppFrame/Console/Console.h"

namespace Star
{

class WindowsConsole:public Console
{
public:
    WindowsConsole();
    ~WindowsConsole();

    virtual void Show() override;

    virtual void Hide() override;

    virtual bool isShow() override;
private:
    // 控制台句柄
    HANDLE m_console;
};

}// namespace Star