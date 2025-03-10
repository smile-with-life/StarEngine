#include "starpch.h"

#include "WindowsWindow.h"

#include "Runtime/Core/Config/Config.h"
#include"Runtime/Core/String/Convert.h"

#include"glad/glad.h"
#include"glad/glad_wgl.h"

namespace Star
{

Window* Window::Create()
{
    return new WindowsWindow();
}

void WindowsWindow::Init()
{
    ConfigFile config;
    config.Load("Asset/Config/Engine.ini");
    {
        // 读取配置文件 @ 实现
        m_props.Mode;//窗口显示模式
        m_props.Type;// 窗口类型
        m_props.Title = config.GetString("window", "Title");//窗口的标题
        m_props.Width = config.GetInt("window", "Width");//窗口的宽度
        m_props.Height = config.GetInt("window", "Height");//窗口的高度
        m_props.PositionX = config.GetInt("window", "PositionX"); //窗口在屏幕上的水平位置
        m_props.PositionY = config.GetInt("window", "PositionY");//窗口在屏幕上垂直水平位置
        m_props.Opacity = config.GetFloat("window", "Opacity");// 窗口透明度
        m_props.IsVSync = config.GetBool("window", "IsVSync");// 是否启用垂直同步
        m_props.IsDisplayTaskbar = config.GetBool("window", "IsDisplayTaskbar");// 窗口是否显示在任务栏中
        m_props.IsTopmost = config.GetBool("window", "IsTopmost");//是否应该位于所有其他窗口之上
        m_props.IsVisible = config.GetBool("window", "IsVisible");// 是否是可见的
        m_props.IsAcceptInput = config.GetBool("window", "IsAcceptInput");//是否允许交互
        m_props.IsHasTitlebar = config.GetBool("window", "IsHasTitlebar");//是否有标题栏
        m_props.IsHasWindowMenu = config.GetBool("window", "IsHasWindowMenu");// 是否有窗口菜单
        m_props.IsHasResizeBorder = config.GetBool("window", "IsHasResizeBorder");//是否有可用于调整大小的边框 
        m_props.IsHasCloseButton = config.GetBool("window", "IsHasCloseButton");//是否有关闭按钮
        m_props.IsHasMinimizeButton = config.GetBool("window", "IsHasMinimizeButton");//是否有最小化按钮
        m_props.IsHasMaximizeButton = config.GetBool("window", "IsHasMaximizeButton");//是否有最大化按钮
        m_props.IsSupportDragFile = config.GetBool("window", "IsSupportDragFile");//是否支持拖拽文件
    }

    uint32 WindowExStyle = 0;
    uint32 WindowStyle = 0;
    WindowExStyle |= WS_EX_WINDOWEDGE;
    //WindowExStyle |= WS_EX_LAYERED;// 窗口支持透明度
    //WindowExStyle |= WS_EX_COMPOSITED;

    if(m_props.IsDisplayTaskbar)
    {
        WindowExStyle |= WS_EX_APPWINDOW;// 当窗口可见时，将顶级窗口强制到任务栏上
    }
    else
    {
        WindowExStyle |= WS_EX_TOOLWINDOW;// 窗口不会显示到任务栏上
    }

    if (m_props.IsSupportDragFile)
    {
        WindowExStyle |= WS_EX_ACCEPTFILES;// 窗口接受拖放文件
    }

    if (m_props.IsTopmost)
    {
        WindowExStyle |= WS_EX_TOPMOST;// 窗口应放置在所有非最顶层的窗口之上，并且应保持其上方
    }

    WindowStyle = WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

    if(!m_props.IsAcceptInput)
    {
        WindowStyle |= WS_DISABLED;// 窗口最初处于禁用状态
    }

    if (m_props.IsHasResizeBorder)
    {
        WindowStyle |= WS_SIZEBOX;// 窗口具有调整大小的边框
    }
    else
    {
        WindowStyle |= WS_BORDER;// 窗口具有细线边框
    }
    
    if (m_props.IsHasTitlebar)
    {
        WindowStyle |= WS_CAPTION;// 窗口具有标题栏
    }

    if (m_props.IsHasWindowMenu)
    {
        WindowStyle |= WS_SYSMENU;// 窗口的标题栏上有一个窗口菜单
        if (m_props.IsHasMinimizeButton)
        {
            WindowStyle |= WS_MINIMIZEBOX;// 窗口具有最小化按钮
        }
        if (m_props.IsHasMaximizeButton)
        {
            WindowStyle |= WS_MAXIMIZEBOX;// 窗口具有最大化按钮
        }
    }

    // 创建窗口
    m_hWnd = ::CreateWindowEx(WindowExStyle,    // 窗口扩展样式
        TEXT("StarEngineWindow"),               // 窗口类名
        Convert::ToWideString(m_props.Title).c_str(),      // 窗口标题
        WindowStyle,                            // 窗口样式
        m_props.PositionX,                      // 窗口的初始水平位置
        m_props.PositionY,                      // 窗口的初始垂直位置
        m_props.Width,                          // 窗口的宽度
        m_props.Height,                         // 窗口的高度
        NULL,                                   // 父窗口句柄
        NULL,                                   // 菜单的句柄
        GWindowsInstance,                       // 应用程序句柄
        NULL);                                  // 传给窗口过程函数的参数

    if (!m_props.IsHasCloseButton)//窗口具有关闭按钮
    {
        EnableMenuItem(GetSystemMenu(m_hWnd, false), SC_CLOSE, MF_GRAYED);
    }

    SetOpacity(m_props.Opacity);

    //if ()
    //{
    //    // Tell OLE that we are opting into drag and drop.
    //    // Only makes sense for regular windows (windows that last a while.)
    //    RegisterDragDrop(m_hWnd, this);

    //    // Listing to clipboard change event
    //    ::AddClipboardFormatListener(m_hWnd);
    //} 文件拖放 @ 实现

}

void WindowsWindow::Tick()
{   

}

void WindowsWindow::Exit()
{

}

void WindowsWindow::SetTitle(const String& title)
{
    m_props.Title = title;
    SetWindowText(m_hWnd, Convert::ToWideString(m_props.Title).c_str());
}

void WindowsWindow::SetWindowMode(WindowMode mode)
{
    m_props.Mode = mode;
    // @ 实现
}

void WindowsWindow::SetOpacity(const float opacity)
{
    m_props.Opacity = opacity;
    SetLayeredWindowAttributes(m_hWnd, 0, static_cast<BYTE>(m_props.Opacity * 255.0f), LWA_ALPHA);
}

void WindowsWindow::SetVSync(bool enabled)
{
    m_props.IsVSync = enabled;
    // @ 实现
}

void WindowsWindow::BringFront()
{
    ::BringWindowToTop(m_hWnd);
}

void WindowsWindow::ResizeWindow(int32 width, int32 height)
{
    m_props.Width = width;
    m_props.Height = height;

    ::MoveWindow(m_hWnd, m_props.PositionX, m_props.PositionY, m_props.Width, m_props.Height, true);
}

void WindowsWindow::MoveWindow(int32 x, int32 y)
{
    m_props.PositionX = x;
    m_props.PositionY = y;

    ::MoveWindow(m_hWnd, m_props.PositionX, m_props.PositionY, m_props.Width, m_props.Height, false);
}

void WindowsWindow::FocusWindow()
{

}

void WindowsWindow::CloseWindow()
{
    ::DestroyWindow(m_hWnd);
}

void WindowsWindow::MinimizeWindow()
{
    ::ShowWindow(m_hWnd, SW_MINIMIZE);
}

void WindowsWindow::MaximizeWindow()
{
    ::ShowWindow(m_hWnd, SW_MAXIMIZE);
}

void WindowsWindow::RestoreWindow()
{
    ::ShowWindow(m_hWnd, SW_RESTORE);
}

void WindowsWindow::ShowWindow()
{
    ::ShowWindow(m_hWnd, SW_SHOW);
}

void WindowsWindow::HideWindow()
{
    ::ShowWindow(m_hWnd, SW_HIDE);
}

void WindowsWindow::EnableWindow(bool enabled)
{
    m_props.IsAcceptInput = enabled;
    ::EnableWindow(m_hWnd, m_props.IsAcceptInput);
}

bool WindowsWindow::IsFront() const
{
    return ::GetForegroundWindow() == m_hWnd;
}

bool WindowsWindow::IsSupportFullscreen() const
{
    return false;
}

bool WindowsWindow::IsMax() const
{
    return ::IsZoomed(m_hWnd);
}

bool WindowsWindow::IsMin() const
{
    return ::IsIconic(m_hWnd);
}

bool WindowsWindow::IsVisible() const
{
    return ::IsWindowVisible(m_hWnd);
}

bool WindowsWindow::IsPointInWindow(int32 x, int32 y) const
{
    return false;
}

bool WindowsWindow::IsVSync() const
{
    return false;
}

std::string WindowsWindow::GetTitle() const
{
    return "";
}

int32 WindowsWindow::GetWidth() const
{
    return int32();
}

int32 WindowsWindow::GetHeight() const
{
    return int32();
}

int32 WindowsWindow::GetPositionX() const
{
    return int32();
}

int32 WindowsWindow::GetPositionY() const
{
    return int32();
}

WindowMode WindowsWindow::GetWindowMode() const
{
    return WindowMode();
}

void* WindowsWindow::GetNativeHandle() const
{
    return m_hWnd;
}
}// namespace Star