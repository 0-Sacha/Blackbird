#pragma once

#include "Platform/WindowPlatform/IWindowPlatform.h"

namespace Blackbird::WindowPlatform::GLFW
{

    class GLFWPlatform final : public IWindowPlatform
    {
    public:
		~GLFWPlatform() override = default;

    public:
        void InitEngineAPI(EngineAPI& api, Ref<Window>& window) override;
        Ref<Window> CreateWindow(const WindowProps& props, PlatformAPI& api) override;
		Scope<ImGuiLayer::IImGuiWindowPlatform> CreateImGuiWindowPlatform() override;

	public:
		float GetTime() override;
	};

}
