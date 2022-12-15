#pragma once

#include "Spitfire/Core/Layer/Layer.h"

#include "Spitfire/Event/ApplicationEvent.h"
#include "Spitfire/Event/KeyboardEvent.h"
#include "Spitfire/Event/MouseEvent.h"

namespace Spitfire {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		virtual ~ImGuiLayer() = default;

	public:
		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& event);
		
	public:
		void BeginFrame();
		void EndFrame();

	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);

	};

}