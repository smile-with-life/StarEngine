#include "starpch.h"

#include "Runtime/Core/Core.h"
#include "Runtime/Launch/EngineLoop.h"
HANDLE g_hOutput = 0;
int32 WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    //AllocConsole();
    //g_hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    int32 error = 0;
    GWindowsInstance = hInstance;

    // 处理命令行参数
    // @ 实现

    Star::GEngineLoop.Init();

    while (!Star::GEngineLoop.IsQuit())
    {
        Star::GEngineLoop.Tick();
    }

    Star::GEngineLoop.Exit();

	return error;
}