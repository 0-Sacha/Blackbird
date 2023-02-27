#include "OpenGLPlatform.h"

#include "Engine/OpenGLRendererCommand.h"
#include "Engine/Asset/OpenGLAssetFactory.h"
#include "Engine/OpenGLShader/OpenGLShaderFactory.h"
#include "Engine/OpenGLTexture/OpenGLTextureFactory.h"

#include "Engine/Context/OpenGLGLFWContext.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
    void OpenGLPlatform::InitEngineAPI(EngineAPI& api)
    {
		api.SetRendererCommand(std::make_unique<OpenGL::OpenGLRendererCommand>());
		api.SetAssetFactory(std::make_unique<OpenGL::OpenGLAssetFactory>());
		api.SetShaderFactory(std::make_unique<OpenGL::OpenGLShaderFactory>());
		api.SetTextureFactory(std::make_unique<OpenGL::OpenGLTextureFactory>());
    }

    std::unique_ptr<IRendererContext> OpenGLPlatform::GetNewGLFWRendererContext(GLFWwindow* window)
	{
		return std::make_unique<OpenGLGLFWContext>(window);
	}
}
