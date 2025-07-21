#pragma once

#include "Core/Core.h"
#include "Platform/Window.h"
#include "Core/Time/Duration.h"
#include "Core/Time/Clock.h"

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

class CORE_API Application
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

	virtual void* GetWindowHandle();
public:
	// 创建应用程序
	static Application* Create();
protected:
	
};

}