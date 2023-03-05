#pragma once

#include "Blackbird/Core/Core.h"

#include "Blackbird/Engine/Context/EngineContext.h"

#include "Blackbird/EngineDetail/Window.h"
#include "Blackbird/EngineDetail/Layer/LayerStack.h"
#include "Blackbird/EngineDetail/Event/ApplicationEvent.h"

#include "Blackbird/EngineDetail/Utils/TimeStep.h"

#include "Blackbird/ImGui/ImGuiLayer.h"

namespace Blackbird
{
	struct ApplicationSpecification
	{
		std::string Name = "Blackbird App";
		uint32_t Width = 1280;
		uint32_t Height = 720;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& specs = ApplicationSpecification{});
		Application(const std::string& name, uint32_t width = 1280, uint32_t height = 720);
		virtual ~Application() = default;

	private:
		void Create(const ApplicationSpecification& specs);

	public:
		void Run();
		void Close();

	public:
		void PushLayer(Ref<Layer> layer);
		void PushOverlay(Ref<Layer> overlay);

	public:
		Window& GetWindow()									{ return *m_Window; }
		EngineCore::LoggerManager::BasicLogger& Logger()	{ return m_Logger; }
		EngineContext& GetEngineContext()					{ return m_EngineContext; }
		ImGuiLayer& GetImGuiLayer()							{ return *m_ImGuiLayer; }

	public:
		void OnEvent(Event& event);
	
	private:
		bool OnWindowClose(WindowCloseEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);

	private:
		MasterEngineContext m_EngineContext;
		Ref<Window> m_Window;
		Ref<ImGuiLayer> m_ImGuiLayer;

		EngineCore::LoggerManager::BasicLogger m_Logger;

		bool m_Running = true;
		bool m_Minimized = false;
		
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	};
}
