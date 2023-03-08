#pragma once

#include "Blackbird/EngineAPI.h"

#include "Platform/GraphicsPlatform/IGraphicsPlatform.h"

#include "Blackbird/EngineDetail/Window.h"
#include "Blackbird/ImGui/ImGuiLayer.h"

namespace Blackbird
{
    class PlatformAPI;
}

namespace Blackbird::WindowPlatform
{
    class IWindowPlatform
    {
	public:
		virtual ~IWindowPlatform() = default;
    
	public:
        virtual void InitEngineAPI(EngineAPI& api, Ref<Window>& window) = 0;
		virtual Ref<Window> CreateWindow(const WindowProps& props, PlatformAPI& api) = 0;
		virtual Scope<ImGuiLayer::IImGuiWindowPlatform> CreateImGuiWindowPlatform() = 0;

	// TODO : It should not be here
	public:
		virtual float GetTime() = 0;
	};
}
