#pragma once

#include "Blackbird/EngineDetail/Layer/Layer.h"

#include "Blackbird/EngineDetail/Event/ApplicationEvent.h"
#include "Blackbird/EngineDetail/Event/KeyboardEvent.h"
#include "Blackbird/EngineDetail/Event/MouseEvent.h"

#include "imgui.h"

namespace Blackbird
{
	class Application;

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer(Application& applicationLinked);
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
		void BeginFrameDockspace();
		void EndFrameDockspace();

	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);

	private:
		Application& m_ApplicationLinked;
	
	private:
		struct DockspaceSpecification
		{
			bool Enable = true;

			bool OPTFullscreen = true;
			bool OPTPading = false;
			ImGuiDockNodeFlags DockspaceFlags = ImGuiDockNodeFlags_None;
			
			bool Open = true;
		};

		DockspaceSpecification m_DockspaceSpecification;
	};

}
