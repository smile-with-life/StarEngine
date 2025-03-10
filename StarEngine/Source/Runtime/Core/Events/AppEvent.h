#pragma once

#include "Common/Events/Event.h"

namespace Star {
class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(unsigned int width, unsigned int height)
		: m_width(width)
		, m_height(height) 
	{}

	static EventType GetStaticType() 
	{
		return EventType::WindowResize;
	} 

	virtual EventType GetEventType() const override 
	{
		return EventType::WindowResize;
	} 

	virtual const char* GetName() const override 
	{
		return "WindowResize";
	}

	virtual int GetCategoryFlags() const override 
	{
		return EventCategoryApplication;
	}

	unsigned int GetWidth() const
	{ 
		return m_width; 
	}

	unsigned int GetHeight() const 
	{
		return m_height; 
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_width << ", " << m_height;
		return ss.str();
	}
private:
	unsigned int m_width;
	unsigned int m_height;
};

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;

	static EventType GetStaticType() 
	{
		return EventType::WindowClose;
	} 
	
	virtual EventType GetEventType() const override 
	{
		return EventType::WindowClose;
	} 

	virtual int GetCategoryFlags() const override 
	{
		return EventCategoryApplication;
	}

	virtual const char* GetName() const override
	{
		return "WindowClose";
	}
};

// WindowFocus, WindowLostFocus, WindowMoved

class AppTickEvent : public Event
{
public:
	AppTickEvent() = default;

	static EventType GetStaticType() {
		return EventType::AppTick;
	} virtual EventType GetEventType() const override {
		return GetStaticType();
	} virtual const char* GetName() const override {
		return "AppTick";
	}
	virtual int GetCategoryFlags() const override {
		return EventCategoryApplication;
	}
};

class AppUpdateEvent : public Event
{
public:
	AppUpdateEvent() = default;

	static EventType GetStaticType() 
	{
		return EventType::AppUpdate;
	} 
	
	virtual EventType GetEventType() const override 
	{
		return GetStaticType();
	} 

	virtual int GetCategoryFlags() const override 
	{
		return EventCategoryApplication;
	}
	
	virtual const char* GetName() const override 
	{
		return "AppUpdate";
	}
};

class AppRenderEvent : public Event
{
public:
	AppRenderEvent() = default;

	static EventType GetStaticType() 
	{
		return EventType::AppRender;
	} 
	
	virtual EventType GetEventType() const override 
	{
		return GetStaticType();
	} 

	virtual int GetCategoryFlags() const override
	{
		return EventCategoryApplication;
	}
	
	virtual const char* GetName() const override 
	{
		return "AppRender";
	}
};
}