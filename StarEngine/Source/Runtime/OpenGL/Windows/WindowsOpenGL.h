#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/OpenGL/OpenGL.h"

namespace Star
{
class WindowsOpenGL:public OpenGL
{
public:
    WindowsOpenGL() = default;
    ~WindowsOpenGL() = default;
public:
    virtual void Init() override;

    virtual void Tick() override;

    virtual void Exit() override;

    virtual void CreateContext(void* windowHandle);
private:
    // 加载OpenGL函数
    void LoadOpenGL();

    // 设置当前上下文
    void MakeContext();

    void LoadWGL();
private:
    // Windows窗口句柄
    HWND m_hWnd = NULL;

    // 设备上下文
    HDC m_hDC = NULL;

    // 渲染上下文
    HGLRC m_hRC = NULL;

    // 像素格式
    PIXELFORMATDESCRIPTOR m_pixelFormat = {};
};
}// namespace Star 


