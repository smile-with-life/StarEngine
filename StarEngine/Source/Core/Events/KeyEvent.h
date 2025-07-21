#pragma once

#include "Common/Events/Event.h"
//#include "Engine/Core/KeyCodes.h"


namespace Star {
using KeyCode = int;
class KeyEvent : public Event
{
public:
	KeyCode GetKeyCode() const 
	{ 
		return m_keycode;
	}

	virtual int GetCategoryFlags() const override 
	{
		return EventCategoryKeyboard | EventCategoryInput;
	}
protected:
	KeyEvent(const KeyCode keycode)
		: m_keycode(keycode)
	{}
protected:
	KeyCode m_keycode;
};

class KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(const KeyCode keycode, bool isRepeat = false)
		: KeyEvent(keycode)
		, m_isRepeat(isRepeat)
	{}

	static EventType GetStaticType() 
	{
		return EventType::KeyPressed;
	} 

	virtual EventType GetEventType() const override 
	{
		return EventType::KeyPressed;
	} 

	virtual const char* GetName() const override
	{
		return "KeyPressed";
	}

	bool IsRepeat() const
	{
		return m_isRepeat;
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_keycode << " (repeat = " << m_isRepeat << ")";
		return ss.str();
	}
private:
	bool m_isRepeat;
};

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(const KeyCode keycode)
		: KeyEvent(keycode) 
	{}

	static EventType GetStaticType() 
	{
		return EventType::KeyReleased;
	} 

	virtual EventType GetEventType() const override 
	{
		return EventType::KeyReleased;
	}
	
	virtual const char* GetName() const override 
	{
		return "KeyReleased";
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_keycode;
		return ss.str();
	}

};

class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(const KeyCode keycode)
		: KeyEvent(keycode) {}

	static EventType GetStaticType() 
	{
		return EventType::KeyTyped;
	} 
	virtual EventType GetEventType() const override 
	{
		return EventType::KeyTyped;
	} 
	
	virtual const char* GetName() const override 
	{
		return "KeyTyped";
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << m_keycode;
		return ss.str();
	}
};
}// namespace Star 
