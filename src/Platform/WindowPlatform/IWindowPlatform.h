#pragma once

#include "Blackbird/EngineAPI.h"

#include "Platform/GraphicsPlatform/IGraphicsPlatform.h"

#include "Blackbird/EngineDetail/Window.h"

namespace Blackbird
{
    class PlatformAPI;
}

namespace Blackbird::WindowPlatform
{
    class IWindowPlatform
    {
    public:
        virtual void InitEngineAPI(EngineAPI& api, Ref<Window>& window) = 0;
        virtual Ref<Window> CreateWindow(const WindowProps& props, PlatformAPI& api) = 0;

	public:
		virtual void ImGUIInit(Window& window) = 0;
		virtual void ImGUIShutdown() = 0;
		virtual void ImGUINewFrame() = 0;
		virtual void ImGuiViewportPass() = 0;
	};
}
