#pragma once

#include "Platform/WindowPlatform/WindowPlatform.h"

namespace Blackbird::WindowPlatform::GLFW
{
    class GLFWPlatform final : public IWindowPlatform
    {
    public:
        void InitEngineAPI(EngineAPI& api) override;
        Scope<Window> CreateWindow(const WindowProps& props, PlatformAPI& api) override;
    };
}
