#pragma once

#include "Platform/GraphicsPlatform/GraphicsPlatform.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
    class OpenGLPlatform final : public IGraphicsPlatform
    {
    public:
        void InitEngineAPI(EngineAPI& api) override;
        std::unique_ptr<IRendererContext> GetNewGLFWRendererContext(GLFWwindow* window) override;
    };
}
