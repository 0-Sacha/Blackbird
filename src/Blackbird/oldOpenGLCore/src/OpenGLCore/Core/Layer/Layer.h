#pragma once

#include "OpenGLCore/Core/Core.h"
#include "OpenGLCore/Core/TimeStep.h"
#include "OpenGLCore/Event/Event.h"

namespace OGLC {

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

