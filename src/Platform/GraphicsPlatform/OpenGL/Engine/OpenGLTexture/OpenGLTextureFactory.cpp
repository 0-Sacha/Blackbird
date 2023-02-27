#include "OpenGLTextureFactory.h"

#include "OpenGLTexture.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	Ref<Texture2D> OpenGLTextureFactory::CreateTexture2D(const std::string& path)
	{
		return std::make_shared<OpenGLTexture2D>(path);
	}
}
