#pragma once

#include "Common/Events/Event.h"
//#include "Hazel/Core/MouseCodes.h"

namespace Star {
using MouseCode = int;
class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(const float x, const float y)
		: m_mouseX(x)
		, m_mouseY(y) 
	{}

	static EventType GetStaticType() 
	{
		return EventType::MouseMoved;
	} 
	
	virtual EventType GetEventType() const override 
	{
		return EventType::MouseMoved;
	} 

	virtual int GetCategoryFlags() const override 
	{
		return EventCategoryMouse | EventCategoryInput;
	}

	virtual const char* GetName() const override 
	{
		return "MouseMoved";
	}

	float GetX() const 
	{
		return m_mouseX; 
	}

	float GetY() const 
	{ 
		return m_mouseY; 
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
		return ss.str();
	}
private:
	float m_mouseX;
	float m_mouseY;
};

class MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(const float xOffset, const float yOffset)
		: m_xOffset(xOffset), m_yOffset(yOffset) {}

	static EventType GetStaticType() 
	{
		return EventType::MouseScrolled;
	}
	
	virtual EventType GetEventType() const override 
	{
		return EventType::MouseScrolled;
	} 
	
	virtual const char* GetName() const override 
	{
		return "MouseScrolled";
	}

	virtual int GetCategoryFlags() const override 
	{
		return EventCategoryMouse | EventCategoryInput;
	}

	float GetXOffset() const 
	{ 
		return m_xOffset; 
	}
	
	float GetYOffset() const 
	{ 
		return m_yOffset; 
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return ss.str();
	}
private:
	float m_xOffset;
	float m_yOffset;
};

class MouseButtonEvent : public Event
{
public:
	MouseCode GetMouseButton() const 
	{ 
		return m_Button; 
	}

	virtual int GetCategoryFlags() const override 
	{
		return EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton;
	}
protected:
	MouseButtonEvent(const MouseCode button)
		: m_Button(button) 
	{}

	MouseCode m_Button;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(const MouseCode button)
		: MouseButtonEvent(button) 
	{}

	static EventType GetStaticType() 
	{
		return EventType::MouseButtonPressed;
	} 
	
	virtual EventType GetEventType() const override
	{
		return EventType::MouseButtonPressed;
	} 
	
	virtual const char* GetName() const override 
	{
		return "MouseButtonPressed";
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button;
		return ss.str();
	}
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(const MouseCode button)
		: MouseButtonEvent(button) 
	{}

	static EventType GetStaticType() 
	{
		return EventType::MouseButtonReleased;
	} 
	
	virtual EventType GetEventType() const override
	{
		return EventType::MouseButtonReleased;
	} 
	
	virtual const char* GetName() const override 
	{
		return "MouseButtonReleased";
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_Button;
		return ss.str();
	}
};

}
