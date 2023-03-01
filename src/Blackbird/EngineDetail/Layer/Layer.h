#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/EngineDetail/Utils/TimeStep.h"
#include "Blackbird/EngineDetail/Event/Event.h"

#include "Blackbird/Engine/Context/EngineContext.h"

namespace Blackbird
{
	class Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		Layer(std::string&& debugName);

		virtual ~Layer() {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(TimeStep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	public:
		void SetEngineContext(EngineContext& context)	{ m_EngineContext = context; }
		void ClearEngineContext()						{ m_EngineContext.Clear(); }

	protected:
		EngineContext m_EngineContext;
		std::string m_DebugName;
	};
}
