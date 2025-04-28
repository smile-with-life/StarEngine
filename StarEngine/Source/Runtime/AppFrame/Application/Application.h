#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/AppFrame/Window/Window.h"
#include "Runtime/Core/Time/Duration.h"
#include "Runtime/Core/Time/Clock.h"

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
class FrameController
{
public:
	FrameController(int32 frame)
		: m_maxFPS(frame)
		, m_frameTime(1000000 / frame)
	{
		
	}
public:
	void Init(int32 frame) 
	{
		m_lastUpdateTime = SteadyClock::Now();
	}

	void Tick() 
	{

		Nanoseconds currentFrameTime = SteadyClock::Now() - m_lastUpdateTime;// 当前帧的时间
		auto delay = m_frameTime - ConvertType<Microseconds>(currentFrameTime);
		if (currentFrameTime < m_frameTime)
		{
			
		}
	}

	void Exit()
	{

	}
private:
	int32 m_maxFPS;// 最大帧率限制
	Microseconds m_frameTime;// 帧时间
	TimePoint<SteadyClock> m_lastUpdateTime;// 上次更新时间
};

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
protected:
	
};

}