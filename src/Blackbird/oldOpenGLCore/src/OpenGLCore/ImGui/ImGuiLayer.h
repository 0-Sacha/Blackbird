#pragma once

#include "OpenGlCore/Core/Layer/Layer.h"

#include "OpenGlCore/Event/ApplicationEvent.h"
#include "OpenGlCore/Event/KeyboardEvent.h"
#include "OpenGlCore/Event/MouseEvent.h"

namespace OGLC {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		virtual ~ImGuiLayer() = default;

	public:
		void OnAttach() override;
		void OnDetach() override;
		void OnImGuiRender() override;
		void OnEvent(Event& event);
		
	public:
		void BeginFrame();
		void EndFrame();

	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);

	};

}