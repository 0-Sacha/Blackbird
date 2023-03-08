#pragma once

#include "Event.h"
#include "Blackbird/EngineDetail/Input/KeyboardKey.h"


// KeyPressed, KeyReleased, KeyTyped,

namespace Blackbird
{

	class KeyboardEvent : public Event
	{
	public:
		KeyboardEvent() = default;
		~KeyboardEvent() override = default;

	public:
		EVENT_CLASS_CATEGORY(EventCategory_Keyboard | EventCategory_Input)
	};

	class KeyEvent : public KeyboardEvent
	{

	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		inline KeyboardKey GetKeyboardKey() const { return (KeyboardKey)m_KeyCode; }

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		KeyEvent(KeyboardKey key)
			: m_KeyCode((int)key) {}

	public:
		~KeyEvent() override = default;
	
	protected:
		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		
		~KeyPressedEvent() override = default;

	public:
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			return ProjectCore::FMT::FormatString("KeyPressedEvent: {} ({} repeats)", m_KeyCode, m_RepeatCount);
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

		~KeyReleasedEvent() override = default;

	public:
		std::string ToString() const override
		{
			return ProjectCore::FMT::FormatString("KeyReleasedEvent: {}", m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}

		~KeyTypedEvent() override = default;

	public:
		std::string ToString() const override
		{
			return ProjectCore::FMT::FormatString("KeyTypedEvent: {}", m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

}
