#pragma once
#include"Runtime/AppFrame/Window/Window.h"
namespace Star
{
class OpenGLPlatform
{
public:
    OpenGLPlatform(Window* window)
        : m_window(window){}
    virtual void LoadOpenGL(){}
    virtual void MakeCurrent(){}
private:
    Window* m_window;
};
}// namespace Star