#pragma once
// 创建一个Windows平台的应用程序

#include "Platform/Application.h"

#include "Platform/Windows/WindowsConsole.h"
#include "Core/Core.h"
#include "Core/Memory/RAII.h"


namespace Star
{
class InputDevice;

class CORE_API WindowsApplication : public Application
{
public:
	WindowsApplication(const HINSTANCE appHandle, const HICON iconHandle);
	virtual ~WindowsApplication();

	// 初始化
	virtual void Init() override;

	// 更新
	virtual void Tick() override;

	// 退出
	virtual void Exit() override;

	// 是否退出
	virtual bool IsQuit() override;

	// 轮询输入设备
	virtual void PollInputDevice() override;

	// 处理消息队列中的消息
	virtual void PumpMessage() override;

	virtual void* GetWindowHandle() override;
protected:
	// 友元函数
	friend LRESULT WinAppWndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam);

    // 窗口过程函数
	static LRESULT CALLBACK AppWndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam);

	// 消息处理函数
	int32 HandleMessage(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam);
private:
	// 注册窗口类
	void RegisterWindowClassInfo(const HINSTANCE hInstance, const HICON hIcon);
private:
	// 输入设备列表
	//Array<InputDevice> m_inputDevices;

	// 主窗口
	ScopePtr<Window> m_window;

	// 控制台
	ScopePtr<Console> m_console;

	// 应用程序句柄
	HINSTANCE m_hInstance;

	// 退出标志
	bool m_isQuit = false;
};
}// namespace Star