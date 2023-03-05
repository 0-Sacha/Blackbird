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

	public:
		void BlockEvent()	{ m_EventBlocked = true; }
		void UnblockEvent() { m_EventBlocked = false; }

	public:
		void EnableDockspace()	{ m_DockspaceData.Enable = true; }
		void DisableDockspace()	{ m_DockspaceData.Enable = false; }

	private:
		void BeginFrameDockspace();
		void EndFrameDockspace();

	private:
		bool OnMouseEvent(Event& event);

	private:
		struct DockspaceData
		{
			bool Enable = false;

			bool OPTFullscreen = true;
			bool OPTPading = false;
			ImGuiDockNodeFlags DockspaceFlags = ImGuiDockNodeFlags_None;
			const char* DockspaceName = "Dockspace";
			const char* DockspaceID = "Dockspace";

			bool Open = true;

			bool IsFrameOpen = false;
		};
	
	private:
		Application& m_ApplicationLinked;
		DockspaceData m_DockspaceData;
		bool m_EventBlocked = false;
	};

}
