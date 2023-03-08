#pragma once

#include "Blackbird/EngineAPI.h"

#include "Blackbird/Engine/Context/IRendererContext.h"
#include "Blackbird/ImGui/ImGuiLayer.h"

struct GLFWwindow;

namespace Blackbird
{
    class PlatformAPI;
}

namespace Blackbird::GraphicsPlatforms
{
    class IGraphicsPlatform
    {
	public:
		virtual ~IGraphicsPlatform() = default;

    public:
        virtual void InitEngineAPI(EngineAPI& api) = 0;
        virtual Scope<IRendererContext> GetNewGLFWRendererContext(GLFWwindow* window) = 0;
		virtual Scope<ImGuiLayer::IImGuiGraphicsPlatform> CreateImGuiGraphicsPlatform() = 0;
	};
}
