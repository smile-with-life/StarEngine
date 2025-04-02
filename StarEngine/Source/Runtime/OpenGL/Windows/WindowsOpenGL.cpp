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

/* member */
void WindowsOpenGL::Init(Window* window_)
{
    m_hWnd = (HWND)(window_->GetNativeHandle());
    LoadOpenGL();
    MakeContext();
}

void WindowsOpenGL::Tick()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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

void WindowsOpenGL::LoadOpenGL()
{
    HWND tempWnd;
    HDC tempDC;
    HGLRC tempRC;

    memset(&m_pixelFormat, 0, sizeof(PIXELFORMATDESCRIPTOR));

    m_pixelFormat.nSize = sizeof(PIXELFORMATDESCRIPTOR);                                  // 像素格式的大小
    m_pixelFormat.nVersion = 1;                                                           // 像素格式的版本
    m_pixelFormat.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;   // 像素缓冲区属性
    m_pixelFormat.iPixelType = PFD_TYPE_RGBA;                                             // 像素数据的类型
    m_pixelFormat.cColorBits = 24;                                                        // 颜色的位数
    m_pixelFormat.cRedBits = 8;                                                           // 红色通道的位数
    m_pixelFormat.cGreenBits = 8;                                                         // 绿色通道的位数
    m_pixelFormat.cBlueBits = 8;                                                          // 蓝色通道的位数
    m_pixelFormat.cAlphaBits = 8;                                                         // alpha通道的位数
    m_pixelFormat.cDepthBits = 24;                                                        // 深度缓冲区的位数
    m_pixelFormat.cStencilBits = 8;                                                       // 模板缓冲区的位数

    // 创建临时窗口
    tempWnd = ::CreateWindowEx(NULL,        // 窗口扩展样式
        TEXT("StarEngineWindow"),           // 窗口类名
        TEXT("LoadOpenGLWindow"),           // 窗口标题
        NULL,                               // 窗口样式
        10,                                 // 窗口的初始水平位置
        10,                                 // 窗口的初始垂直位置
        500,                                // 窗口的宽度
        500,                                // 窗口的高度
        NULL,                               // 父窗口句柄
        NULL,                               // 菜单的句柄
        GWindowsInstance,                   // 应用程序句柄
        NULL);                              // 传给窗口过程函数的参数

    // 获取临时窗口的设备上下文
    tempDC = GetDC(tempWnd);
    Assert(tempDC);

    // 设置临时的默认像素格式
    SetPixelFormat(tempDC, 1, &m_pixelFormat);

    // 创建一个临时渲染上下文
    tempRC = wglCreateContext(tempDC);

    // 将临时渲染上下文设置为此窗口的当前渲染上下文
    wglMakeCurrent(tempDC, tempRC);

    // 加载OpenGL的WGL扩展
    gladLoadWGL(tempDC);

    // 加载OpenGL的函数
    gladLoadGLLoader((GLADloadproc)wglGetProcAddress);

    // 将当前渲染上下文置空
    wglMakeCurrent(NULL, NULL);

    // 释放临时渲染上下文
    wglDeleteContext(tempRC);

    // 释放该窗口的设备上下文。
    ReleaseDC(tempWnd, tempDC);
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

    // 启用背面剔除.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}
}// namespace Star
