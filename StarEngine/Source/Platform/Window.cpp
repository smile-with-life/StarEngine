#include"starpch.h"

#include"Window.h"

namespace Star
{
Window::Window()
{

}

Window::~Window()
{

}

void Window::Init()
{

}

void Window::Tick()
{

}

void Window::Exit()
{

}

void Window::SetTitle(const String& title)
{

}

void Window::SetWindowMode(WindowMode mode)
{

}

void Window::SetOpacity(const float opacity)
{

}

void Window::SetVSync(bool enabled)
{

}

void Window::BringFront()
{

}

void Window::ResizeWindow(int32 Width, int32 Height)
{

}

void Window::MoveWindow(int32 x, int32 y)
{

}

void Window::FocusWindow()
{

}

void Window::CloseWindow()
{

}

void Window::MinimizeWindow()
{

}

void Window::MaximizeWindow()
{

}

void Window::RestoreWindow()
{

}

void Window::ShowWindow()
{

}

void Window::HideWindow()
{

}

void Window::EnableWindow(bool enable)
{

}

bool Window::IsFront() const
{
    return false;
}

bool Window::IsSupportFullscreen() const
{
    return false;
}

bool Window::IsMax() const
{
    return false;
}

bool Window::IsMin() const
{
    return false;
}

bool Window::IsVisible() const
{
    return false;
}

bool Window::IsPointInWindow(int32 x, int32 y) const
{
    return false;
}

bool Window::IsVSync() const
{
    return false;
}

std::string Window::GetTitle() const
{
    return "";
}

int32 Window::GetWidth() const
{
    return 0;
}

int32 Window::GetHeight() const
{
    return 0;
}

int32 Window::GetPositionX() const
{
    return 0;
}

int32 Window::GetPositionY() const
{
    return 0;
}

WindowMode Window::GetWindowMode() const
{
    return WindowMode::None;
}

void* Window::GetNativeHandle() const
{
    return nullptr;
}

}// namespace Star