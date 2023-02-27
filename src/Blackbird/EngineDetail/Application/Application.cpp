

#include "Application.h"

#include "Blackbird/Core/Core.h"
#include "Blackbird/EngineDetail/Input/Input.h"
#include "Blackbird/Engine/Renderer/Renderer.h"

#include "Blackbird/EngineAPI.h"
#include "Platform/PlatformAPI.h"

#include "Platform/WindowPlatform/GLFW/GLFWPlatform.h"
#include "Platform/GraphicsPlatform/OpenGL/OpenGLPlatform.h"

#include "Platform/WindowPlatform/GLFW/Window/GLFWWindow.h"

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
		PlatformAPI::GetInstance().SetWindowPlatform(std::make_unique<WindowPlatform::GLFW::GLFWPlatform>());
		PlatformAPI::GetInstance().SetGraphicsPlatform(std::make_unique<GraphicsPlatform::OpenGL::OpenGLPlatform>());

		PlatformAPI::GetInstance().GetWindowPlatform().InitEngineAPI(EngineAPI::GetInstance());
		PlatformAPI::GetInstance().GetGraphicsPlatform().InitEngineAPI(EngineAPI::GetInstance());

		if(s_Instance)
			BLACKBIRD_ASSERT(false, "Application already exists!");
		s_Instance = this;

		m_Window.reset(new WindowPlatform::GLFW::GLFWWindow({ specs.Name, specs.Width, specs.Height }, PlatformAPI::GetInstance()));
		m_Window->SetEventCallback(BLACKBIRD_BIND_APPEVENT(OnEvent));

		Renderer::Init();
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
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

		Renderer::OnWindowResize(event.GetWidth(), event.GetHeight());

		return false;
	}
}