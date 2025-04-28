#include "starpch.h"

#include "Runtime/Core/Core.h"
#include "Runtime/Launch/MainLoop.h"

int32 WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    int32 error = 0;
    GWindowsInstance = hInstance;

    // 处理命令行参数
    // @ 实现

    Star::GMainLoop.Init();

    while (!Star::GMainLoop.IsQuit())
    {
        Star::GMainLoop.Tick();
    }

    Star::GMainLoop.Exit();

	return error;
}