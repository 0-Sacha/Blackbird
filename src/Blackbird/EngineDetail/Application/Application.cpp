#include "Application.h"

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Renderer/Renderer.h"

#include "Blackbird/Engine/BlackbirdStatic/S_Application.h"

namespace Blackbird
{
	Application::Application(const ApplicationSpecification& specs)
		: m_LayerStack(this)
	{
		Create(specs);
	}

	Application::Application(const std::string& name, uint32_t width, uint32_t height)
		: m_LayerStack(this)
	{
		ApplicationSpecification specs;
		specs.Name = name;
		specs.Width = width;
		specs.Height = height;
		Create(specs);
	}

	Application::~Application()
	{
		Destroy();
	}

	void Application::Create(const ApplicationSpecification& specs)
	{
		m_Logger.SetName(specs.Name);

		m_EngineContext.InitPlatformAPI();

		m_Window = m_EngineContext.Platform().CreateWindow({ specs.Name, specs.Width, specs.Height });
		m_Window->SetEventCallback(BLACKBIRD_BIND_EVENT(OnEvent));

		m_EngineContext.InitEngineAPI(m_Window);
		m_EngineContext.CreateRenderer();
		m_EngineContext.CreateRenderer2D();

		m_ImGuiLayer = std::make_shared<ImGuiLayer>(
			m_EngineContext.Platform().WindowPlatform().CreateImGuiWindowPlatform(),
			m_EngineContext.Platform().GraphicsPlatform().CreateImGuiGraphicsPlatform());
		PushOverlay(m_ImGuiLayer);

		S_Application::SetDefaultApplication(this);
	}

	void Application::Destroy()
	{
		m_LayerStack.ForEach([](Ref<Layer>& layer) {
			layer->OnDetach();
			});
		m_LayerStack.Clear();
		m_ImGuiLayer = nullptr;

#ifdef BLACKBIRD_ENABLE_LOGGER
		if (m_Window.use_count() > 2)
			BLKBID_WARN("Window uses: {}", m_Window.use_count());
#endif
		m_Window = nullptr;

		m_EngineContext.Destroy();
	}

	void Application::Close()
	{
		m_Running = false;
	}

	void Application::Run()
	{
		while(m_Running)
		{
			float time = (float)m_EngineContext.Platform().WindowPlatform().GetTime();
			TimeStep timeStep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				m_LayerStack.ForEach([timeStep](Ref<Layer>& layer)
					{
						layer->OnUpdate(timeStep);
					});
			}

			m_ImGuiLayer->BeginFrame();
			m_LayerStack.ForEach([](Ref<Layer>& layer)
				{
					layer->OnImGuiRender();
				});
			m_ImGuiLayer->EndFrame();

			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Ref<Layer> layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Ref<Layer> overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::OnEvent(Event& event)
	{
		BLACKBIRD_EVENT_TRACE(event);

		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BLACKBIRD_BIND_EVENT(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BLACKBIRD_BIND_EVENT(OnWindowResize));

		m_LayerStack.ForEachReverseStopable([&event](Ref<Layer>& layer)
			{
				layer->OnEvent(event);
				return event.Handled;
			});
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		Close();
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
