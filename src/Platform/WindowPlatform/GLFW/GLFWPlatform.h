#pragma once

#include "Platform/WindowPlatform/IWindowPlatform.h"

namespace Blackbird::WindowPlatform::GLFW
{

    class GLFWPlatform final : public IWindowPlatform
    {
    public:
        void InitEngineAPI(EngineAPI& api, Ref<Window>& window) override;
        Ref<Window> CreateWindow(const WindowProps& props, PlatformAPI& api) override;

	public:
		void ImGUIInit(Window& window) override;
		void ImGUIShutdown() override;
		void ImGUINewFrame() override;
		void ImGuiViewportPass() override;
	};

}
