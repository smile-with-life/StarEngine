#include "starpch.h"


#include "Common/Events/ApplicationEvent.h"
#include "Common/Events/KeyEvent.h"
#include "Common/Events/MouseEvent.h"

namespace Star
{
static uint8_t s_GLFWWindowCount = 0;
//
//static void GLFWErrorCallback(int error, const char* description)
//{
//	HZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
//}

void WindowsWindow::Init(const WindowProps& props)
{
	m_data.Title = props.Title;
	m_data.Width = props.Width;
	m_data.Height = props.Height;

	std::cout << std::format("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

	if (s_GLFWWindowCount == 0)
	{
		int success = glfwInit();
		//glfwSetErrorCallback(GLFWErrorCallback);
	}


	m_window = glfwCreateWindow((int)props.Width, (int)props.Height, m_data.Title.c_str(), nullptr, nullptr);
	++s_GLFWWindowCount;

	glfwMakeContextCurrent(m_window);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSetWindowUserPointer(m_window, &m_data);
	SetVSync(true);

	// 设置 GLFW 回调
	glfwSetWindowSizeCallback(m_window, 
		[](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));		
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.Callback(event);
		});

	glfwSetWindowCloseCallback(m_window, 
		[](GLFWwindow* window)
		{
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			WindowCloseEvent event;
			data.Callback(event);
		});

	glfwSetKeyCallback(m_window, 
		[](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.Callback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.Callback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, true);
				data.Callback(event);
				break;
			}
			}
		});

	glfwSetCharCallback(m_window, 
		[](GLFWwindow* window, unsigned int keycode)
		{
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			KeyTypedEvent event(keycode);
			data.Callback(event);
		});

	glfwSetMouseButtonCallback(m_window, 
		[](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.Callback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.Callback(event);
				break;
			}
			}
		});

	glfwSetScrollCallback(m_window, 
		[](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.Callback(event);
		});

	glfwSetCursorPosCallback(m_window, 
		[](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.Callback(event);
		});
}

}// namespace Star