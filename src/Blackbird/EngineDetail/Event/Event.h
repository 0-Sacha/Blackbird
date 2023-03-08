#pragma once

#include "Blackbird/Core/Core.h"

#define BLACKBIRD_BIND_EVENT(eventFunction) [this](auto& event) { return this->eventFunction(event); }

#define BLACKBIRD_SET_BIT(i) (1 << i)

#ifdef BLACKBIRD_ENABLE_EVENT_TRACE
	#define BLACKBIRD_EVENT_TRACE(event) BLACKBIRD_TRACE("{}", event.ToString());
#else
	#define BLACKBIRD_EVENT_TRACE(event)
#endif

namespace Blackbird {

	enum class EventType : int
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategory_Application	= BLACKBIRD_SET_BIT(0),
		EventCategory_Input			= BLACKBIRD_SET_BIT(1),
		EventCategory_Keyboard		= BLACKBIRD_SET_BIT(2),
		EventCategory_Mouse			= BLACKBIRD_SET_BIT(3),
		EventCategory_MouseButton	= BLACKBIRD_SET_BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::type; }\
								EventType GetEventType() const override { return GetStaticType(); }\
								const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		virtual ~Event() = default;

	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		inline bool Dispatch(const std::function<bool(T& event)>& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& stream, const Event& e)
	{
		return stream << e.ToString();
	}

}

namespace ProjectCore::FMT
{
	template<typename FormatContext>
	struct FormatterType<Blackbird::Event, FormatContext>
	{
		inline static void Format(const Blackbird::Event& t, FormatContext& context) {
			FormatterType<std::string>::Format(t.ToString(), context);
		}
	};
}
