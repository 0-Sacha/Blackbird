#pragma once

#include "OpenGlCore/Core/Core.h"

#include "OpenGlCore/Core/Window.h"
#include "OpenGlCore/Core/Layer/LayerStack.h"
#include "OpenGlCore/Event/ApplicationEvent.h"

#include "OpenGlCore/Core/TimeStep.h"

#include "OpenGlCore/ImGui/ImGuiLayer.h"


#define OGC_BIND_APPEVENT(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace OGLC {

	class Application
	{
	public:
		Application(const std::string& name = "OpenGlCore App", uint32_t width = 1280, uint32_t height = 720);
		virtual ~Application() = default;

	public:
		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& GetInstance() { return *s_Instance; };

		inline static CPPTools::LogSystem& Logger() {
			return CPPTools::LogSystem("Application", CPPTools::LogSystem::LogSeverity::Trace);
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

}