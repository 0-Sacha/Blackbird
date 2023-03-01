#pragma once

#include "Platform/GraphicsPlatform/GraphicsPlatform.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
    class OpenGLPlatform final : public IGraphicsPlatform
    {
    public:
        void InitEngineAPI(EngineAPI& api) override;
        Scope<IRendererContext> GetNewGLFWRendererContext(GLFWwindow* window) override;
    };
}
