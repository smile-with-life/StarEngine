#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/AppFrame/Window/Window.h"
#include "Runtime/Core/Time/Time.h"
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

// 引擎帧管理器
class FrameManager
{
public:
	void Init()
	{
		m_startTime = m_lastStatisticTime = Clock::NowTime();
	}

	void Tick()
	{
		auto duration = m_frameStartTime - m_lastStatisticTime;
		if (duration > std::chrono::seconds(1)) 
		{
			m_FPS = m_frameCount;
			m_frameCount = 0;
			m_lastStatisticTime = m_frameStartTime;
		}
		else 
		{
			m_frameCount++;
		}
	}

	void Exit();
private:
	Time m_startTime;// 引擎开始时间
	Time m_lastUpdateTime;// 上次更新时间
	Time m_frameStartTime;// 帧开始时间
	Time m_frameEndTime;// 帧结束时间
	Time m_lastStatisticTime;// 上次统计的时间
	int32 m_frameCount = 0;// 自上次统计以来的帧数
	float m_FPS = 0.0;// 帧率
	Nanoseconds m_deltaTime;// 存储当前帧与上一帧的时间差
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