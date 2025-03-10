#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/AppFrame/Window/Window.h"

namespace Star 
{

//struct CmdArgs
//{
//	int count = 0;
//	char** args = nullptr;
//
//	const char* operator[](int index) const
//	{
//		return args[index];
//	}
//};
class SE_API Application
{
public:
	Application() = default;
	virtual ~Application() = default;

	// 初始化
	virtual void Init();

	// 更新
	virtual void Tick();

	// 退出
	virtual void Exit();

	// 是否退出
	virtual bool IsQuit();

	// 轮询输入设备
	virtual void PollInputDevice();

	// 处理消息队列中的消息
	virtual void PumpMessage();
public:
	// 创建应用程序
	static Application* Create();
};
}