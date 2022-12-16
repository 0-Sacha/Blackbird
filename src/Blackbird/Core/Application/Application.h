#pragma once

#include "Blackbird/Core/Core.h"

#include "Blackbird/Core/Window.h"
#include "Blackbird/Core/Layer/LayerStack.h"
#include "Blackbird/Event/ApplicationEvent.h"

#include "Blackbird/Core/TimeStep.h"

#include "Blackbird/ImGui/ImGuiLayer.h"


#define OGC_BIND_APPEVENT(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Blackbird {

	class Application
	{
	public:
		Application(const std::string& name = "Blackbird App", uint32_t width = 1280, uint32_t height = 720);
		virtual ~Application() = default;

	public:
		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& GetInstance() { return *s_Instance; };

		inline static inline EngineCore::LoggerManager::BasicLogger& Logger() {
			static auto instance = EngineCore::LoggerManager::BasicLogger("Application", EngineCore::LoggerManager::LogSeverity::Trace);
			return instance;
		}

	private:
		bool OnWindowClose(WindowCloseEvent& event);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}