#pragma once

#include "Blackbird/EngineAPI.h"

#include "Blackbird/Engine/Context/RendererContext.h"

struct GLFWwindow;

namespace Blackbird::GraphicsPlatform
{
    class IGraphicsPlatform
    {
    public:
        virtual void InitEngineAPI(EngineAPI& api) = 0;
        virtual std::unique_ptr<IRendererContext> GetNewGLFWRendererContext(GLFWwindow* window) = 0;
	};
}
