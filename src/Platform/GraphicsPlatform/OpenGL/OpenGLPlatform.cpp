#include "OpenGLPlatform.h"

#include "Engine/OpenGLRendererCommand.h"
#include "Engine/Asset/OpenGLAssetFactory.h"
#include "Engine/OpenGLShader/OpenGLShaderFactory.h"
#include "Engine/OpenGLTexture/OpenGLTextureFactory.h"

#include "Engine/OpenGLFramebuffer/OpenGLFramebufferFactory.h"

#include "Engine/Context/OpenGLGLFWContext.h"

#include "OpenGLImGuiInclude.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
    void OpenGLPlatform::InitEngineAPI(EngineAPI& api)
    {
		api.SetRendererCommand(std::make_unique<OpenGL::OpenGLRendererCommand>());
		api.SetAssetFactory(std::make_unique<OpenGL::OpenGLAssetFactory>());
		api.SetShaderFactory(std::make_unique<OpenGL::OpenGLShaderFactory>());
		api.SetTextureFactory(std::make_unique<OpenGL::OpenGLTextureFactory>());

		api.SetFramebufferFactory(std::make_unique<OpenGL::OpenGLFramebufferFactory>());
    }

	Scope<IRendererContext> OpenGLPlatform::GetNewGLFWRendererContext(GLFWwindow* window)
	{
		return std::make_unique<OpenGLGLFWContext>(window);
	}

	void OpenGLPlatform::ImGUIInit()
	{
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void OpenGLPlatform::ImGUIShutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
	}

	void OpenGLPlatform::ImGUINewFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
	}

	void OpenGLPlatform::ImGuiRender()
	{
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

}
