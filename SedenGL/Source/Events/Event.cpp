#include "Event.h"
#include "Log.h"

namespace Seden {

	//------------- MousePressEvent -------------
	MousePressEvent::MousePressEvent(int button, int mod)
		: button(button), mod(mod) {}
	EventType MousePressEvent::getEventType()
	{
		return EventType::MOUSE_PRESSED;
	}
	void MousePressEvent::print()
	{
		SEDEN_INFO("Mouse pressed : %i, %i",button,mod)
	}

	//------------- MouseReleaseEvent -------------
	MouseReleaseEvent::MouseReleaseEvent(int button, int mod)
		: button(button), mod(mod) {}
	EventType MouseReleaseEvent::getEventType()
	{
		return EventType::MOUSE_RELEASED;
	}
	void MouseReleaseEvent::print()
	{
		SEDEN_INFO("Mouse released : %i, %i", button, mod)
	}
	
	//------------- WindowCloseEvent -------------
	WindowCloseEvent::WindowCloseEvent(){}

	EventType WindowCloseEvent::getEventType()
	{
		return EventType::WINDOW_CLOSE;
	}
	void WindowCloseEvent::print()
	{
		SEDEN_INFO("Close button pressed")
	}

	//------------- KeyPressedEvent -------------
	KeyPressedEvent::KeyPressedEvent(int key)
		: key(key) {}
	EventType KeyPressedEvent::getEventType()
	{
		return EventType::KEY_PRESSED;
	}
	void KeyPressedEvent::print()
	{
		SEDEN_INFO("Key pressed : %i", key)
	}

	//------------- KeyPressedEvent -------------
	KeyReleasedEvent::KeyReleasedEvent(int key)
		: key(key) {}
	EventType KeyReleasedEvent::getEventType()
	{
		return EventType::KEY_RELEASED;
	}
	void KeyReleasedEvent::print()
	{
		SEDEN_INFO("Key Released : %i", key)
	}

	//------------- KeyRepeatEvent -------------
	KeyRepeatEvent::KeyRepeatEvent(int key)
		: key(key) {}
	EventType KeyRepeatEvent::getEventType()
	{
		return EventType::KEY_REPEAT;
	}
	void KeyRepeatEvent::print()
	{
		SEDEN_INFO("Key Repeat : %i", key)
	}

	//------------- CursorPosEvent -------------
	CursorPosEvent::CursorPosEvent(float xPos, float yPos)
		:xPos(xPos), yPos(yPos) {}
	EventType CursorPosEvent::getEventType()
	{
		return EventType::CURSOR_POSITION;
	}
	void CursorPosEvent::print()
	{
		SEDEN_INFO("mouse position : %f, %f", xPos, yPos)
	}
}