#include "OpenGLTextureFactoryImpl.h"

#include "OpenGLTexture.h"

namespace Blackbird::Platform::OpenGL
{
	Ref<Texture2D> OpenGLTextureFactoryImpl::CreateTexture2D(const std::string& path)
	{
		return std::make_shared<OpenGLTexture2D>(path);
	}
}
