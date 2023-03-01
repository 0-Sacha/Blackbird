#pragma once

#include "Blackbird/EngineDetail/Layer/Layer.h"

#include "Blackbird/EngineDetail/Event/ApplicationEvent.h"
#include "Blackbird/EngineDetail/Event/KeyboardEvent.h"
#include "Blackbird/EngineDetail/Event/MouseEvent.h"

namespace Blackbird
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override {}

	public:
		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& event);
		void OnImGuiRender() override;
		
	public:
		void BeginFrame();
		void EndFrame();

	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
	};
}
