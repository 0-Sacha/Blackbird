#pragma once

#include "Event.h"
#include "Blackbird/EngineDetail/Input/KeyboardKey.h"


// KeyPressed, KeyReleased, KeyTyped,

namespace Blackbird {

	class KeyEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategory_Keyboard | EventCategory_Input)

		inline int GetKeyCode() const { return m_KeyCode; }
		inline KeyboardKey GetKeyboardKey() const { return (KeyboardKey)m_KeyCode; }

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		KeyEvent(KeyboardKey key)
			: m_KeyCode((int)key) {}

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override {
			std::string str;
			EngineCore::FMT::FormatInString(str, "KeyPressedEvent: {} ({} repeats)", m_KeyCode, m_RepeatCount);
			return str;
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override {
			std::string str;
			EngineCore::FMT::FormatInString(str, "KeyReleasedEvent: {}", m_KeyCode);
			return str;
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override {
			std::string str;
			EngineCore::FMT::FormatInString(str, "KeyTypedEvent: {}", m_KeyCode);
			return str;
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

}
