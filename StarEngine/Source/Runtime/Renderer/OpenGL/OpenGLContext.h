#pragma once
#include"Runtime/AppFrame/Window/Window.h"
namespace Star
{
class OpenGLContext
{
public:
    OpenGLContext(Window* window);

    void Init();

    void SwapBuffers();
private:
    Window* m_window;
};
}// namespace Star