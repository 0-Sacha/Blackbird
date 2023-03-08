#pragma once

#include "Blackbird/EngineDetail/Layer/Layer.h"

#include "Blackbird/EngineDetail/Event/AllEvent.h"
#include "Blackbird/EngineDetail/Window.h"

#include "imgui.h"

namespace Blackbird
{
	class Application;

	class ImGuiLayer : public Layer
	{
	public:
		class IImGuiWindowPlatform;
		class IImGuiGraphicsPlatform;

	public:
		ImGuiLayer(Scope<IImGuiWindowPlatform>&& _IImGuiLayerWindowPlatform, Scope<IImGuiGraphicsPlatform>&& _IImGuiLayerGrpahicsPlatform);
		~ImGuiLayer() override = default;

	public:
		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& event) override;
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
		Scope<IImGuiWindowPlatform> m_IImGuiWindowPlatform;
		Scope<IImGuiGraphicsPlatform> m_IImGuiGraphicsPlatform;

		DockspaceData m_DockspaceData;
		bool m_EventBlocked = false;
	};


	class ImGuiLayer::IImGuiWindowPlatform
	{
	public:
		virtual ~IImGuiWindowPlatform() = default;

	public:
		virtual void InitImpl(Window& window) = 0;
		virtual void ShutdownImpl() = 0;
		virtual void NewFrameImpl() = 0;
		virtual void ViewportPassImpl() = 0;
	};

	class ImGuiLayer::IImGuiGraphicsPlatform
	{
	public:
		virtual ~IImGuiGraphicsPlatform() = default;

	public:
		virtual void InitImpl() = 0;
		virtual void ShutdownImpl() = 0;
		virtual void NewFrameImpl() = 0;
		virtual void OnRenderImpl() = 0;
	};

}
