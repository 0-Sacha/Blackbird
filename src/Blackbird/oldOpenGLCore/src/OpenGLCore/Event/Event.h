#pragma once

#include "OpenGlCore/Core/Core.h"

#define OGLC_BIND_EVENT(fn) std::bind(&fn, this, std::placeholders::_1)
#define OGLC_SET_BIT(i) (1 << i)

#ifdef OGLC_ENABLE_EVENT_TRACE
	#define OGLC_EVENT_TRACE(event) OGLC_TRACE("{}", event.ToString());
#else
	#define OGLC_EVENT_TRACE(event)
#endif

namespace OGLC {

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
		EventCategory_Application	= OGLC_SET_BIT(0),
		EventCategory_Input			= OGLC_SET_BIT(1),
		EventCategory_Keyboard		= OGLC_SET_BIT(2),
		EventCategory_Mouse			= OGLC_SET_BIT(3),
		EventCategory_MouseButton	= OGLC_SET_BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
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

		// F will be deduced by the compiler
		template<typename T, typename F>
		inline bool Dispatch(const F& func)
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

namespace CPPTools::Fmt {

	template<>
	struct FormatType<OGLC::Event>
	{
		inline static void Write(const OGLC::Event& t, Formater& formater, const FormatData& data) {
			FormatType<std::string>::Write(t.ToString(), formater, data);
		}
	};

}