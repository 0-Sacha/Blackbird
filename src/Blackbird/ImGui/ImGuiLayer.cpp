#include "ImGuiLayer.h"

#include "Blackbird/EngineDetail/Application/Application.h"


namespace Blackbird
{
	ImGuiLayer::ImGuiLayer(Application& applicationLinked)
		: Layer("ImGuiLayer")
		, m_ApplicationLinked(applicationLinked)
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

		m_ApplicationLinked.GetEngineContext().Platform().WindowPlatform().ImGUIInit(m_ApplicationLinked.GetWindow());
		m_ApplicationLinked.GetEngineContext().Platform().GraphicsPlatform().ImGUIInit();
	}

	void ImGuiLayer::OnDetach()
	{
		m_ApplicationLinked.GetEngineContext().Platform().GraphicsPlatform().ImGUIShutdown();
		m_ApplicationLinked.GetEngineContext().Platform().WindowPlatform().ImGUIShutdown();

		ImGui::DestroyContext();
	}

	void ImGuiLayer::BeginFrame()
	{
		m_ApplicationLinked.GetEngineContext().Platform().GraphicsPlatform().ImGUINewFrame();
		m_ApplicationLinked.GetEngineContext().Platform().WindowPlatform().ImGUINewFrame();

		ImGui::NewFrame();

		if (m_DockspaceSpecification.Enable)
			BeginFrameDockspace();
	}

	void ImGuiLayer::EndFrame()
	{
		if (m_DockspaceSpecification.Enable)
			EndFrameDockspace();

		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)m_ApplicationLinked.GetWindow().GetWidth(), (float)m_ApplicationLinked.GetWindow().GetHeight());

		// Rendering
		ImGui::Render();
		m_ApplicationLinked.GetEngineContext().Platform().GraphicsPlatform().ImGuiRender();

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			m_ApplicationLinked.GetEngineContext().Platform().WindowPlatform().ImGuiViewportPass();
		}
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(BLACKBIRD_BIND_EVENT(ImGuiLayer::OnMouseButtonPressed));
	}

	void ImGuiLayer::OnImGuiRender()
	{
	}

	void ImGuiLayer::BeginFrameDockspace()
	{
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (m_DockspaceSpecification.OPTFullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->GetWorkPos());
			ImGui::SetNextWindowSize(viewport->GetWorkSize());
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}
		else
		{
			m_DockspaceSpecification.DockspaceFlags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
		}

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
		// and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (m_DockspaceSpecification.DockspaceFlags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		if (!m_DockspaceSpecification.OPTPading)
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

		ImGui::Begin("DockSpace Demo", &m_DockspaceSpecification.Open, window_flags);
		if (!m_DockspaceSpecification.OPTPading)
			ImGui::PopStyleVar();

		if (m_DockspaceSpecification.OPTFullscreen)
			ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), m_DockspaceSpecification.DockspaceFlags);
		}
	}

	void ImGuiLayer::EndFrameDockspace()
	{
		ImGui::End();
	}

	bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		ImGuiIO io = ImGui::GetIO();
		return io.WantCaptureMouse;
	}

}
