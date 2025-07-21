#include"starpch.h"

#include"WindowsApplication.h"

#include"Platform/Windows/WindowsWindow.h"



namespace Star
{
WindowsApplication* WindowsApp = nullptr;

/* static */
Application* Application::Create()
{
    HICON hIcon = NULL;// @ 实现 

    WindowsApp = new WindowsApplication(GWindowsInstance, hIcon);
    return WindowsApp;
}

/* public */
WindowsApplication::WindowsApplication(const HINSTANCE hInstance, const HICON hIcon)
    : Application()
    , m_hInstance(hInstance)
{
    RegisterWindowClassInfo(m_hInstance, hIcon);

    m_console = ScopePtr<Console>(Console::Create());
    m_window = ScopePtr<Window>(Window::Create());

    // 初始化了 OLE 库，以支持拖放功能
    // CA_SUPPRESS(6031);
    // OleInitialize(NULL);

    // 文本输入系统 @ ...

    // 任务栏列表初始化 @ 实现
}

WindowsApplication::~WindowsApplication()
{

    // ::CoUninitialize();
    // OleUninitialize();
}

void WindowsApplication::Init()
{   
    m_console->Init();
    m_window->Init();
}

void WindowsApplication::Tick()
{
    PumpMessage();
    m_window->Tick();
}

void WindowsApplication::Exit()
{
    m_window->Exit();
}

bool WindowsApplication::IsQuit()
{
    return m_isQuit;
}

void WindowsApplication::PollInputDevice()
{
    // @ 实现
}

void WindowsApplication::PumpMessage()
{
    // Windows窗口消息
    MSG msg;

    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        // 翻译消息
        ::TranslateMessage(&msg);

        // 分发消息
        DispatchMessage(&msg);
    }
}

void* WindowsApplication::GetWindowHandle()
{
    return m_window->GetNativeHandle();
}

/* protected */
LRESULT WinAppWndProc(HWND hWnd, uint32 msg, WPARAM wParam, LPARAM lParam)
{
    return WindowsApp->HandleMessage(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK WindowsApplication::AppWndProc(HWND hWnd, uint32 msg, WPARAM wParam, LPARAM lParam)
{
    return WinAppWndProc(hWnd, msg, wParam, lParam);
}

int32 WindowsApplication::HandleMessage(HWND hWnd, uint32 msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_NULL:// 空消息
    {
        break;
    }
    // 窗口
    case WM_ACTIVATE:// 窗口激活状态改变时发送
    {
        break;
    }
    case WM_ACTIVATEAPP:// 应用程序的激活状态改变时发送
    {
        break;
    }
    case WM_CHILDACTIVATE:// 用户点击子窗口的标题栏或激活、移动窗口或调整其大小时发送，这是一个内部操作
    {
        break;
    }
    case WM_NCACTIVATE:// 当窗口的非工作区激活状态改变时发送
    {
        break;
    }
    case WM_INPUTLANGCHANGE:// 在应用程序的输入语言被更改后发送
    {
        break;
    }
    case WM_INPUTLANGCHANGEREQUEST:// 当用户选择新的输入语言时发送（可以拒绝更改）
    {
        break;
    }
    case WM_KILLFOCUS:// 失去输入焦点时发送
    {
        break;
    }
    case WM_SETFOCUS:// 获得键盘焦点后发送
    {
        break;
    }
    case WM_PAINT:// 窗口的工作区绘制时发送
    {
        break;
    }
    case WM_NCPAINT:// 窗口的非工作区绘制时发送
    {
        break;
    }
    case WM_SHOWWINDOW:// 当窗口即将隐藏或显示时发送
    {
        break;
    }
    case WM_QUERYOPEN:// 当用户请求将窗口还原到其以前的大小和位置时发送
    {
        break;
    }
    case WM_CLOSE:// 窗口关闭时发送
    {
        SendMessage(hWnd, WM_QUIT, 0, 0);
        break;
    }
    case WM_NCCALCSIZE:// 计算窗口工作区的大小和位置时发送
    {
        break;
    }
    case WM_WINDOWPOSCHANGED:// 当窗口的位置或大小即将改变时发送
    {
        break;
    }
    case WM_WINDOWPOSCHANGING:// 当窗口的位置或大小已经改变后发送
    {
        break;
    }
    case WM_MOVE:// 移动窗口后发送
    {
        break;
    }
    case WM_MOVING:// 移动窗口时发送
    {
        break;
    }
    case WM_SIZE:// 窗口大小改变后发送
    {
        break;
    }
    case WM_SIZING:// 窗口大小改变时发送
    {
        break;
    }
    case WM_CREATE:// 创建窗口时发送（新窗口的窗口过程在窗口创建后、窗口变为可见之前接收此消息）
    {
        break;
    }
    case WM_DESTROY:// 窗口被销毁时发送
    {
        break;
    }
    case WM_NCCREATE:// 在首次创建窗口时 WM_CREATE消息之前 发送
    {
        break;
    }
    case WM_NCDESTROY:// 窗口的非工作区被销毁时发送
    {
        break;
    }
    case WM_ENTERSIZEMOVE:// 窗口进入移动或调整大小模式时发送
    {
        break;
    }
    case WM_EXITSIZEMOVE:// 窗口退出移动或调整大小模式时发送
    {
        break;
    }
    case WM_GETICON:// 检索与窗口关联的图标的句柄，返回值是图标的句柄
    {
        break;
    }
    case WM_GETMINMAXINFO:// 当窗口的大小或位置即将更改时发送（可以控制窗口显示时的最大最小限制）
    {
        break;
    }
    case WM_QUERYDRAGICON:// 查询任务栏图标在被拖动时应该显示的图标或光标，返回一个光标或图标的句柄
    {
        break;
    }
    case WM_COMPACTING:// 系统内存不足时发送
    {
        break;
    }
    case WM_CANCELMODE:// 通知一个应用程序取消当前的内部模态操作
    {
        break;
    }
    case WM_QUIT:// 在应用程序调用 PostQuitMessage 函数时生成，此消息导致 GetMessage 函数返回零
    {
        m_isQuit = true;
        break;
    }
    case WM_ENABLE:// 应用程序更改窗口的启用状态时发送
    {
        break;
    }
    case WM_STYLECHANGED:// 在 SetWindowLong 函数更改了一个或多个窗口样式后发送
    {
        break;
    }
    case WM_STYLECHANGING://当 SetWindowLong 函数即将更改窗口的一个或多个样式时发送
    {
        break;
    }
    case WM_THEMECHANGED:// 在主题更改事件后发送
    {
        break;
    }
    case WM_SETTINGCHANGE:// 应用程序更改系统参数时发送
    {
        break;
    }
    case WM_DPICHANGED:// 设备的DPI设置改变时发送
    {
        break;
    }
    case WM_DISPLAYCHANGE:// 显示设置（如分辨率或颜色深度）改变时发送
    {
        break;
    }
    case WM_ENDSESSION:// 当用户关闭操作系统时发送
    {
        break;
    }
    // 原始输入
    case WM_INPUT:// 进行输入时发送到正在获取原始输入的窗口
    {
        break;
    }
    case WM_INPUT_DEVICE_CHANGE:// 输入设备发生改变时发送到接收原始输入的窗口
    {
        break;
    }
    case WM_APPCOMMAND:// 生成应用程序命令时发送
    {
        break;
    }
    // 键盘
    case WM_CHAR:// 当 TranslateMessage 函数翻译 WM_KEYDOWN 消息时发送（按下键的字符代码）
    {
        break;
    }
    case WM_DEADCHAR:// 当 TranslateMessage 函数翻译 WM_KEYUP 消息时发送（按下键的字符代码）
    {
        break;
    }
    case WM_SYSDEADCHAR://当 TranslateMessage 函数翻译WM_SYSKEYDOWN消息时发送（按下键的字符代码）
    {
        break;
    }
    case WM_KEYDOWN:// 非系统键按下时发送
    {
        break;
    }
    case WM_KEYUP:// 非系统键抬起时发送 
    {
        break;
    }
    case WM_SYSKEYDOWN:// 系统键按下时发送
    {
        break;
    }
    case WM_SYSKEYUP:// 系统键抬起时发送
    {
        break;
    }
    // 鼠标
    case WM_LBUTTONDBLCLK:// 在工作区双击鼠标左键时发送
    {
        break;
    }
    case WM_MBUTTONDBLCLK:// 在工作区双击鼠标中键时发送
    {
        break;
    }
    case WM_RBUTTONDBLCLK:// 在工作区双击鼠标右键时发送
    {
        break;
    }
    case WM_XBUTTONDBLCLK:// 在工作区双击鼠标扩展按键时发送
    {
        break;
    }
    case WM_LBUTTONDOWN:// 在工作区按下鼠标左键时发送
    {
        break;
    }
    case WM_MBUTTONDOWN:// 在工作区按下鼠标中键时发送
    {
        break;
    }
    case WM_RBUTTONDOWN:// 在工作区按下鼠标右键时发送
    {
        break;
    }
    case WM_XBUTTONDOWN:// 在工作区按下鼠标扩展按键时发送
    {
        break;
    }
    case WM_LBUTTONUP:// 在工作区抬起鼠标左键时发送
    {
        break;
    }
    case WM_MBUTTONUP:// 在工作区抬起鼠标中键时发送 
    {
        break;
    }
    case WM_RBUTTONUP:// 在工作区抬起鼠标右键时发送
    {
        break;
    }
    case WM_XBUTTONUP:// 在工作区抬起鼠标扩展按键时发送
    {
        break;
    }
    case WM_MOUSEHOVER:// 当鼠标悬停在窗口的工作区上时发送
    {
        break;
    }
    case WM_MOUSELEAVE:// 当鼠标离开指定的窗口工作区时发送
    {
        break;
    }
    case WM_MOUSEMOVE:// 鼠标在窗口的工作区移动时发送
    {
        break;
    }
    case WM_NCLBUTTONDBLCLK:// 在非工作区双击鼠标左键时发送
    {
        break;
    }
    case WM_NCMBUTTONDBLCLK:// 在非工作区双击鼠标中键时发送
    {
        break;
    }
    case WM_NCRBUTTONDBLCLK:// 在非工作区双击鼠标右键时发送
    {
        break;
    }
    case WM_NCXBUTTONDBLCLK:// 在非工作区双击鼠标扩展按键时发送
    {
        break;
    }
    case WM_NCLBUTTONDOWN:// 在非工作区按下鼠标左键时发送
    {
        break;
    }
    case WM_NCMBUTTONDOWN:// 在非工作区按下鼠标中键时发送
    {
        break;
    }
    case WM_NCRBUTTONDOWN:// 在非工作区按下鼠标右键时发送
    {
        break;
    }
    case WM_NCXBUTTONDOWN:// 在非工作区按下鼠标扩展按键时发送
    {
        break;
    }
    case WM_NCLBUTTONUP:// 在非工作区抬起鼠标左键时发送
    {
        break;
    }
    case WM_NCMBUTTONUP:// 在非工作区抬起鼠标中键时发送   
    {
        break;
    }
    case WM_NCRBUTTONUP:// 在非工作区抬起鼠标右键时发送
    {
        break;
    }
    case WM_NCXBUTTONUP:// 在非工作区抬起鼠标扩展按键时发送
    {
        break;
    }
    case WM_NCMOUSEHOVER:// 当鼠标悬停在窗口的非工作区上时发送
    {
        break;
    }
    case WM_NCMOUSELEAVE:// 当鼠标离开指定的窗口非工作区时发送
    {
        break;
    }
    case WM_NCMOUSEMOVE:// 鼠标在窗口的非工作区移动时发送
    {
        break;
    }
    case WM_MOUSEWHEEL:// 鼠标滚轮垂直滚动
    {
        break;
    }
    case WM_MOUSEHWHEEL:// 鼠标滚轮水平滚动
    {
        break;
    }
    case WM_NCHITTEST:// 鼠标当前坐标
    {
        break;
    }
    default:
    {
        break;
    }
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

/* private */
void WindowsApplication::RegisterWindowClassInfo(const HINSTANCE hInstance, const HICON hIcon)
{
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    // 窗口类设置
    wc.cbSize = sizeof(WNDCLASSEX);                                // 窗口类结构的大小
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;                 // 窗口样式
    wc.lpfnWndProc = AppWndProc;                                   // 窗口消息处理函数
    wc.cbClsExtra = 0;                                             // 窗口类结构的额外字节数
    wc.cbWndExtra = 0;                                             // 窗口实例后分配的额外字节数
    wc.hInstance = hInstance;                                      // 应用程序实例句柄
    wc.hIcon = hIcon;                                              // 窗口图标
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);                      // 鼠标指针样式
    wc.hbrBackground = NULL;                                       // 窗口背景颜色
    wc.lpszMenuName = NULL;                                        // 窗口使用的菜单栏
    wc.lpszClassName = TEXT("StarEngineWindow");                   // 窗口类名
    wc.hIconSm = 0;                                                // 窗口小图标

    // 注册窗口类
	if (!::RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION | MB_OK);
	}
}


}// namespace Star