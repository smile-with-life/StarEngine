#pragma once

//#include "Hazel/Debug/Instrumentor.h"
//#include "Hazel/Core/Base.h"
//
#include "Common/Core/Base.h"
#include "string"  
#include< sstream>                     

namespace Star {
enum class EventType
{
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,AppTick, AppUpdate, AppRender,
	KeyPressed, KeyReleased, KeyTyped,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory
{
	None = 0,
	EventCategoryApplication    = BIT(0),//应用程序事件
	EventCategoryInput          = BIT(1),//输入事件
	EventCategoryKeyboard       = BIT(2),//键盘事件
	EventCategoryMouse          = BIT(3),//鼠标事件
	EventCategoryMouseButton    = BIT(4)//鼠标按键事件
};

class Event
{
public:
	Event() = default;
	virtual ~Event() = default;

	virtual EventType GetEventType() const = 0;
	virtual int GetCategoryFlags() const = 0;
	virtual const char* GetName() const = 0;

	virtual std::string ToString() const
	{ 
		return GetName(); 
	}

	bool IsInCategory(EventCategory category)
	{
		return GetCategoryFlags() & category;
	}

	void ConsumeEvent()
	{
		m_handled = true;
	}

public:
	bool m_handled = false;//已处理标志
};

class EventDispatcher
{
public:
	EventDispatcher(Event& event)
		: m_event(event)
	{}
		
	template<class T, class Func>
	bool Dispatch(const Func& func)
	{
		if (m_event.GetEventType() == T::GetStaticType())
		{
			func(static_cast<T&>(m_event));
			return true;
		}
		return false;
	}
private:
	Event& m_event;
};

inline std::ostream& operator<<(std::ostream& os, const Event& event)
{
	return os << event.ToString();
}
}// namespace Star

