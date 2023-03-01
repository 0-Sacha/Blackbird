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
		api.SetRendererCommand(CreateScope<OpenGL::OpenGLRendererCommand>());
		api.SetAssetFactory(CreateScope<OpenGL::OpenGLAssetFactory>());
		api.SetShaderFactory(CreateScope<OpenGL::OpenGLShaderFactory>());
		api.SetTextureFactory(CreateScope<OpenGL::OpenGLTextureFactory>());
    }

	Scope<IRendererContext> OpenGLPlatform::GetNewGLFWRendererContext(GLFWwindow* window)
	{
		return std::make_unique<OpenGLGLFWContext>(window);
	}
}
