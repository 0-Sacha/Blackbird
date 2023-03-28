#pragma once

#include "Blackbird/EngineDetail/Application/Application.h"

namespace Blackbird
{

    class S_Application
    {
	public:
        static void SetDefaultApplication(Application* defaultApplication) { s_Application = defaultApplication; }

	public:
		static void Run()											{ return s_Application->Run(); }
		static void Close()											{ return s_Application->Close();}
		static void PushLayer(Ref<Layer> layer)						{ return s_Application->PushLayer(layer); }
		static void PushOverlay(Ref<Layer> overlay)					{ return s_Application->PushOverlay(overlay); }
		static Window& GetWindow()									{ return s_Application->GetWindow(); }
		static ProjectCore::LoggerManager::BasicLogger& Logger()	{ return s_Application->Logger(); }
		static EngineContext& GetEngineContext()					{ return s_Application->GetEngineContext(); }
		static ImGuiLayer& GetImGuiLayer()							{ return s_Application->GetImGuiLayer(); }
		static void OnEvent(Event& event)							{ return s_Application->OnEvent(event); }

	public:
        static inline EngineAPI& Engine()           { return GetEngineContext().Engine(); }
        static inline PlatformAPI& Platform()       { return GetEngineContext().Platform();}
		static inline Renderer& GetRenderer()       { return GetEngineContext().GetRenderer(); }
		static inline Renderer2D& GetRenderer2D()   { return GetEngineContext().GetRenderer2D(); }
		static inline Ref<EngineAPI>& EngineRef()			{ return GetEngineContext().EngineRef(); }
		static inline Ref<PlatformAPI>& PlatformRef()		{ return GetEngineContext().PlatformRef(); }
		static inline Ref<Renderer>& GetRendererRef()		{ return GetEngineContext().GetRendererRef(); }
		static inline Ref<Renderer2D>& GetRenderer2DRef()	{ return GetEngineContext().GetRenderer2DRef(); }

    private:
        static inline Application* s_Application = nullptr;
    };

}
