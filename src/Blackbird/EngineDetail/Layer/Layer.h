#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/EngineDetail/Utils/TimeStep.h"
#include "Blackbird/EngineDetail/Event/Event.h"

namespace Blackbird
{
	class Application;

	class Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		Layer(std::string&& debugName);
		virtual ~Layer() = default;

	public:
		void OnAttachLayer(Application* applicationLinked) { m_ApplicationLinked = applicationLinked; OnAttach(); }
		void OnDetachLayer(Application* applicationLinked) { BLACKBIRD_ASSERT(m_ApplicationLinked == applicationLinked); OnDetach(); }

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(TimeStep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		Application* m_ApplicationLinked;
		std::string m_DebugName;
	};
}
