#include "ImGuiLayer.h"

#include "Blackbird/EngineDetail/Application/Application.h"

namespace Blackbird
{
	ImGuiLayer::ImGuiLayer(Scope<IImGuiWindowPlatform>&& _IImGuiWindowPlatform, Scope<IImGuiGraphicsPlatform>&& _IImGuiGraphicsPlatform)
		: Layer("ImGuiLayer")
		, m_IImGuiWindowPlatform(std::move(_IImGuiWindowPlatform))
		, m_IImGuiGraphicsPlatform(std::move(_IImGuiGraphicsPlatform))
	{}

	void ImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		//io.ConfigViewportsNoAutoMerge = true;
		//io.ConfigViewportsNoTaskBarIcon = true;


		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		m_IImGuiWindowPlatform->InitImpl(m_ApplicationLinked->GetWindow());
		m_IImGuiGraphicsPlatform->InitImpl();
	}

	void ImGuiLayer::OnDetach()
	{
		m_IImGuiWindowPlatform->ShutdownImpl();
		m_IImGuiGraphicsPlatform->ShutdownImpl();

		ImGui::DestroyContext();
	}

	void ImGuiLayer::BeginFrame()
	{
		m_IImGuiWindowPlatform->NewFrameImpl();
		m_IImGuiGraphicsPlatform->NewFrameImpl();

		ImGui::NewFrame();

		if (m_DockspaceData.Enable)
		{
			BeginFrameDockspace();
			m_DockspaceData.IsFrameOpen = true;
		}
	}

	void ImGuiLayer::EndFrame()
	{
		if (m_DockspaceData.IsFrameOpen)
		{
			EndFrameDockspace();
			m_DockspaceData.IsFrameOpen = false;
		}

		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)m_ApplicationLinked->GetWindow().GetWidth(), (float)m_ApplicationLinked->GetWindow().GetHeight());

		// Rendering
		ImGui::Render();
		m_IImGuiGraphicsPlatform->OnRenderImpl();

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			m_IImGuiWindowPlatform->ViewportPassImpl();
		}
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(BLACKBIRD_BIND_EVENT(OnMouseEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(BLACKBIRD_BIND_EVENT(OnMouseEvent));
	}

	void ImGuiLayer::OnImGuiRender()
	{
	}

	void ImGuiLayer::BeginFrameDockspace()
	{
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (m_DockspaceData.OPTFullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->WorkPos);
			ImGui::SetNextWindowSize(viewport->WorkSize);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}
		else
		{
			m_DockspaceData.DockspaceFlags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
		}

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
		// and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (m_DockspaceData.DockspaceFlags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		if (!m_DockspaceData.OPTPading)
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

		ImGui::Begin(m_DockspaceData.DockspaceName, &m_DockspaceData.Open, window_flags);
		if (!m_DockspaceData.OPTPading)
			ImGui::PopStyleVar();

		if (m_DockspaceData.OPTFullscreen)
			ImGui::PopStyleVar(2);

		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID(m_DockspaceData.DockspaceID);
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), m_DockspaceData.DockspaceFlags);
		}
	}

	void ImGuiLayer::EndFrameDockspace()
	{
		ImGui::End();
	}

	bool ImGuiLayer::OnMouseEvent(Event& e)
	{
		if (m_EventBlocked)
			return false;
		ImGuiIO io = ImGui::GetIO();
		return io.WantCaptureMouse || io.WantCaptureKeyboard;
	}

}
