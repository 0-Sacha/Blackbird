#pragma once

#include "Platform/GraphicsPlatform/IGraphicsPlatform.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{

    class OpenGLPlatform final : public IGraphicsPlatform
    {
    public:
        void InitEngineAPI(EngineAPI& api) override;
        Scope<IRendererContext> GetNewGLFWRendererContext(GLFWwindow* window) override;

	public:
		void ImGUIInit() override;
		void ImGUIShutdown() override;
		void ImGUINewFrame() override;
		void ImGuiRender() override;
	};

}
