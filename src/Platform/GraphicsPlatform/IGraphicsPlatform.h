#pragma once

#include "Blackbird/EngineAPI.h"

#include "Blackbird/Engine/Context/IRendererContext.h"

struct GLFWwindow;

namespace Blackbird
{
    class PlatformAPI;
}

namespace Blackbird::GraphicsPlatform
{
    class IGraphicsPlatform
    {
	public:
		virtual ~IGraphicsPlatform() = default;

    public:
        virtual void InitEngineAPI(EngineAPI& api) = 0;
        virtual Scope<IRendererContext> GetNewGLFWRendererContext(GLFWwindow* window) = 0;

	public:
		virtual void ImGUIInit() = 0;
		virtual void ImGUIShutdown() = 0;
		virtual void ImGUINewFrame() = 0;
		virtual void ImGuiRender() = 0;
	};
}
