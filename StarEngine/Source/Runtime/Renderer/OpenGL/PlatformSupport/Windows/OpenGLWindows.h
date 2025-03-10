#pragma once
#include"Runtime/Core/Core.h"
#include"Runtime/Renderer/OpenGL/PlatformSupport/OpenGLPlatform.h"


namespace Star
{ 
class OpenGLWindows: public OpenGLPlatform
{
public:
    OpenGLWindows(Window* window);
    virtual void LoadOpenGL() override;
    virtual void MakeCurrent() override;
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
