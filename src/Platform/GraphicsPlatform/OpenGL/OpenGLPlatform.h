#pragma once

#include "Platform/GraphicsPlatform/IGraphicsPlatform.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{

    class OpenGLPlatform final : public IGraphicsPlatform
    {
    public:
		~OpenGLPlatform() override = default;

    public:
        void InitEngineAPI(EngineAPI& api) override;
        Scope<IRendererContext> GetNewGLFWRendererContext(GLFWwindow* window) override;
		Scope<ImGuiLayer::IImGuiGraphicsPlatform> CreateImGuiGraphicsPlatform() override;
	};

}
