#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Utils/TimeStep.h"
#include "Blackbird/Engine/Event/Event.h"

namespace Blackbird {

	class Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		Layer(std::string&& debugName);

		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(TimeStep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}

