#pragma once

#include "Platform/WindowPlatform/WindowPlatform.h"

#include "Platform/GraphicsPlatform/GraphicsPlatform.h"

namespace Blackbird::WindowPlatform::GLFW
{
    class GLFWPlatform final : public IWindowPlatform
    {
    public:
        void InitEngineAPI(EngineAPI& api) override;
    };
}
