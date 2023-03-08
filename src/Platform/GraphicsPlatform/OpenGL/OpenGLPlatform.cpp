#include "OpenGLPlatform.h"

#include "Engine/OpenGLRendererCommand.h"
#include "Engine/Asset/OpenGLAssetFactory.h"
#include "Engine/OpenGLShader/OpenGLShaderFactory.h"
#include "Engine/OpenGLTexture/OpenGLTextureFactory.h"

#include "Engine/OpenGLFramebuffer/OpenGLFramebufferFactory.h"

#include "Engine/Context/OpenGLGLFWContext.h"

#include "ImGui/OpenGLImGuiPlatform.h"

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

	Scope<ImGuiLayer::IImGuiGraphicsPlatform> OpenGLPlatform::CreateImGuiGraphicsPlatform()
	{
		return std::make_unique<OpenGLImGuiPlatform>();
	}

}
