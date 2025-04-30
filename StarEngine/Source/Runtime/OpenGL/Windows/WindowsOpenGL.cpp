#include "starpch.h"
#include "WindowsOpenGL.h"

#include"glad/glad.h"
#include"glad/glad_wgl.h"

// Test
#include "Runtime/Core/String/String.h"

// 
namespace Star
{
/* static */
OpenGL* OpenGL::Create()
{
    return new WindowsOpenGL();
}

static LRESULT CALLBACK TmpWndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uiMsg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, uiMsg, wParam, lParam);
    }

    return 0;
}

/* member */
void WindowsOpenGL::Init()
{
    // 加载 OpenGL 函数
    LoadOpenGL();
}

void WindowsOpenGL::Tick()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    SwapBuffers(m_hDC);
}

void WindowsOpenGL::Exit()
{
    // 将当前渲染上下文置空
    wglMakeCurrent(NULL, NULL);

    // 释放渲染上下文
    wglDeleteContext(m_hRC);

    // 释放该窗口的设备上下文。
    ReleaseDC(m_hWnd, m_hDC);
}

void WindowsOpenGL::MakeContext()
{
    int formatIndexs[1];
    unsigned int formatCount;
    int result;

    // 在属性列表中设置OpenGL的4.0版本
    const int version[] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
        WGL_CONTEXT_MINOR_VERSION_ARB, 0,
        0
    };

    const int attributes[] = {
        WGL_SUPPORT_OPENGL_ARB, TRUE,
        WGL_DRAW_TO_WINDOW_ARB,TRUE,
        WGL_DOUBLE_BUFFER_ARB,TRUE,
        WGL_SWAP_METHOD_ARB,WGL_SWAP_EXCHANGE_ARB,
        WGL_ACCELERATION_ARB,WGL_FULL_ACCELERATION_ARB,
        WGL_COLOR_BITS_ARB,24,
        WGL_RED_BITS_ARB,		8,
        WGL_GREEN_BITS_ARB,		8,
        WGL_BLUE_BITS_ARB,		8,
        WGL_DEPTH_BITS_ARB,24,
        WGL_PIXEL_TYPE_ARB,WGL_TYPE_RGBA_ARB,
        WGL_STENCIL_BITS_ARB,8,
        0
    };


    //获取此窗口的设备上下文。
    m_hDC = GetDC(m_hWnd);

    // 查询适合我们所需属性的像素格式.
    result = wglChoosePixelFormatARB(m_hDC, attributes, NULL, 1, formatIndexs, &formatCount);


    // 如果显卡/显示器可以处理所需的像素格式，则将其设置为当前像素格式。
    result = SetPixelFormat(m_hDC, formatIndexs[0], &m_pixelFormat);
    
    // 创建OpenGL 3.0渲染上下文.
    m_hRC = wglCreateContextAttribsARB(m_hDC, 0, version);


    // 将渲染上下文设置为活动状态.
    result = wglMakeCurrent(m_hDC, m_hRC);


    // 将深度缓冲区设置为完全清除为1.0值.
    glClearDepth(1.0f);

    //启用深度测试.
    glEnable(GL_DEPTH_TEST);

    // 将多边形绕组设置为左手系统的正面.
    glFrontFace(GL_CW);

    // 启用背面剔除
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void WindowsOpenGL::LoadOpenGL()
{
    int result = 0;
    WNDCLASSEX tempWndClass;// 窗口类
    PIXELFORMATDESCRIPTOR pixelFormatDescriptor;// 像素格式描述
    HGLRC tempRenderContext;// 渲染上下文
    HINSTANCE hInstance = GetModuleHandle(NULL);
 
    memset(&tempWndClass, 0, sizeof(WNDCLASSEX));
    memset(&pixelFormatDescriptor, 0, sizeof(PIXELFORMATDESCRIPTOR));

    // 窗口类设置
    tempWndClass.cbSize = sizeof(WNDCLASSEX);
    tempWndClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    tempWndClass.lpfnWndProc = TmpWndProc;
    tempWndClass.hInstance = hInstance;
    tempWndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    tempWndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    tempWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    tempWndClass.lpszClassName = TEXT("InitWindow");

    // 注册窗口类
    if (!::RegisterClassEx(&tempWndClass))
    {
        MessageBox(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION | MB_OK);
        Assert(false);
    }

    // 创建临时窗口
    HWND tempWnd = CreateWindowEx(WS_EX_APPWINDOW, TEXT("InitWindow"), TEXT("InitWindow"), 0, 0, 0, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    
    // 设置像素格式描述
    pixelFormatDescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pixelFormatDescriptor.nVersion = 1;
    pixelFormatDescriptor.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
    pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
    pixelFormatDescriptor.cColorBits = 32;
    pixelFormatDescriptor.cRedBits = 8;
    pixelFormatDescriptor.cGreenBits = 8;
    pixelFormatDescriptor.cBlueBits = 8;
    pixelFormatDescriptor.cAlphaBits = 8;
    pixelFormatDescriptor.cDepthBits = 24;
    pixelFormatDescriptor.cStencilBits = 8;
    pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;

    // 获取临时窗口的设备上下文
    HDC tempDC = GetDC(tempWnd);

    // 查找可供选择的像素格式
    int pixelFormatHandle = ChoosePixelFormat(tempDC, &pixelFormatDescriptor);

    if (!pixelFormatHandle)
    {
        std::cout << "未找到与描述格式相匹配的像素格式" << std::endl;
        Assert(false);
    }

    // 将选定的像素格式绑定到临时窗口的设备上下文
    result = SetPixelFormat(tempDC, pixelFormatHandle, &pixelFormatDescriptor);
    if (result != 1)
    {
        std::cout << "绑定像素格式失败" << std::endl;
        Assert(false);
    }

    // 创建临时OpenGL渲染上下文
    tempRenderContext = wglCreateContext(tempDC);
    if (tempRenderContext == NULL)
    {
        std::cout << "渲染上下文创建失败" << std::endl;
        Assert(false);
    }

    // 激活临时上下文
    result = wglMakeCurrent(tempDC, tempRenderContext);
    if (result != 1)
    {
        std::cout << "设置临时窗口的当前上下文失败" << std::endl;
        Assert(false);
    }

    // 加载WGL函数
    result = gladLoadWGL(tempDC);
    if (!result)
    {
        std::cout << "加载 WGL 扩展失败" << std::endl;
        Assert(false);
    }

    // 加载OpenGL的函数
    gladLoadGLLoader((GLADloadproc)wglGetProcAddress);
    result = gladLoadGL();
    if (!result)
    {
        std::cout << "OpenGL函数加载失败！" << std::endl;
        Assert(false);
    }

    // 释放当前上下文
    wglMakeCurrent(NULL, NULL);

    // 删除临时上下文
    wglDeleteContext(tempRenderContext);

    // 释放临时窗口的设备上下文
    ReleaseDC(tempWnd, tempDC);

    // 销毁临时窗口
    DestroyWindow(tempWnd);
}

void WindowsOpenGL::CreateContext(void* windowHandle)
{
    
    m_hWnd = (HWND)windowHandle;
    m_hDC = GetDC(m_hWnd);

    int pixelFormatHandle;// 可供使用的像素格式句柄
    UINT formatCount;// 可供使用的像素格式的数量
    PIXELFORMATDESCRIPTOR pixelFormatDescriptor;// 像素格式描述
    int result;

    // 现代上下文的创建
    if (GLAD_WGL_ARB_pixel_format && GLAD_WGL_ARB_multisample && GLAD_WGL_ARB_create_context)
    {
        // 像素格式配置
        const int pixelAttr[] = {
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
            WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
            WGL_PIXEL_TYPE_ARB,     WGL_TYPE_RGBA_ARB,
            WGL_COLOR_BITS_ARB,     (int)24,
            WGL_RED_BITS_ARB,		(int)8,
            WGL_GREEN_BITS_ARB,		(int)8,
            WGL_BLUE_BITS_ARB,		(int)8,
            WGL_ALPHA_BITS_ARB,		(int)8,
            WGL_DEPTH_BITS_ARB,     (int)24,
            WGL_STENCIL_BITS_ARB,   (int)8,
            WGL_SAMPLE_BUFFERS_ARB, 1,  // 启用MSAA
            WGL_SAMPLES_ARB,        4,  // 4倍采样
            0
        };

        // 上下文属性配置
        const int contextAttr[] = {
            WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
            WGL_CONTEXT_MINOR_VERSION_ARB, 1,
            WGL_CONTEXT_FLAGS_ARB,         WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
            WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            0
        };

        // 高级像素格式查找
        result = wglChoosePixelFormatARB(m_hDC, pixelAttr, nullptr, 1, &pixelFormatHandle, &formatCount);
        if (!result)
        {
            std::cout << "高级像素格式查找失败" << std::endl;
            Assert(false);
        }

        // 设置像素格式
        result = SetPixelFormat(m_hDC, pixelFormatHandle, &pixelFormatDescriptor);
        if (result != 1)
        {
            std::cout << "设置像素格式失败" << std::endl;
            Assert(false);
        }

        // 创建渲染上下文
        m_hRC = wglCreateContextAttribsARB(m_hDC, 0, contextAttr);
        if (m_hRC == NULL)
        {
            std::cout << " 创建渲染上下文失败" << std::endl;
            Assert(false);
        }

        // 设置当前窗口的上下文
        result = wglMakeCurrent(m_hDC, m_hRC);
        if (result != 1)
        {
            std::cout << " 创建渲染上下文失败" << std::endl;
            Assert(false);
        }

    }
    else
    {
        std::cout << "不支持现代图形API，请升级显卡" << std::endl;
        Assert(false);
    }
}

}// namespace Star
