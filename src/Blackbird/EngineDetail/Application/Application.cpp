

#include "Application.h"

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Renderer/Renderer.h"

#include "Blackbird/Engine/Static/StaticContext.h"

#include <glfw/glfw3.h>

namespace Blackbird
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& specs)
	{
		Create(specs);
	}

	Application::Application(const std::string& name, uint32_t width, uint32_t height)
	{
		ApplicationSpecification specs;
		specs.Name = name;
		specs.Width = width;
		specs.Height = height;
		Create(specs);
	}

	void Application::Create(const ApplicationSpecification& specs)
	{
		if(s_Instance)
			BLACKBIRD_ASSERT(false, "Application already exists!");

		s_Instance = this;

		m_EngineContext.InitPlatformAPI();

		m_Window = m_EngineContext.Platform().CreateWindow({ specs.Name, specs.Width, specs.Height });
		m_Window->SetEventCallback(BLACKBIRD_BIND_APPEVENT(OnEvent));

		m_EngineContext.InitEngineAPI();
		m_EngineContext.CreateRenderer();
		m_EngineContext.CreateRenderer2D();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		StaticContext::SetEngineContext(m_EngineContext);
	}

	void Application::Destroy()
	{
		m_EngineContext.Destroy();
	}

	void Application::Run()
	{
		while(m_Running) {
			float time = (float)glfwGetTime();
			TimeStep timeStep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timeStep);
			}

			m_ImGuiLayer->BeginFrame();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->EndFrame();

			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::OnEvent(Event& event)
	{
		BLACKBIRD_EVENT_TRACE(event);

		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BLACKBIRD_BIND_APPEVENT(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BLACKBIRD_BIND_APPEVENT(OnWindowResize));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin() && !event.Handled; )
			(*--it)->OnEvent(event);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& event)
	{
		if (event.GetWidth() == 0 || event.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}
		m_Minimized = false;

		m_EngineContext.OnWindowResize(event.GetWidth(), event.GetHeight());

		return false;
	}
}
