#pragma once

namespace Seden {

	enum EventType {
		MOUSE_PRESSED,
		MOUSE_RELEASED,
		MOUSE_MOVED,

		WINDOW_CLOSE,

		KEY_PRESSED,
		KEY_RELEASED,
		KEY_REPEAT,

		CURSOR_POSITION,
	};

	class Event {
	public:
		virtual EventType getEventType() = 0;
		virtual void print() = 0;
	};

	class MousePressEvent : public Event {
	public:
		MousePressEvent(int button, int mod);
		EventType getEventType() override;
		void print() override;
	private:
		int button;
		int mod;
	};

	class MouseReleaseEvent : public Event {
	public:
		MouseReleaseEvent(int button, int mod);
		EventType getEventType() override;
		void print() override;
	private:
		int button;
		int mod;
	};

	class WindowCloseEvent : public Event {
	public:
		WindowCloseEvent();
		EventType getEventType() override;
		void print() override;
	};

	class KeyPressedEvent : public Event {
	public:
		KeyPressedEvent(int key);
		EventType getEventType() override;
		void print() override;
	private:
		int key;
	};

	class KeyReleasedEvent : public Event {
	public:
		KeyReleasedEvent(int key);
		EventType getEventType() override;
		void print() override;
	private:
		int key;
	};

	class KeyRepeatEvent : public Event {
	public:
		KeyRepeatEvent(int key);
		EventType getEventType() override;
		void print() override;
	private:
		int key;
	};

	class CursorPosEvent : public Event {
	public:
		CursorPosEvent(float xPos, float yPos);
		EventType getEventType() override;
		void print() override;
	private:
		float xPos, yPos;
	};
}