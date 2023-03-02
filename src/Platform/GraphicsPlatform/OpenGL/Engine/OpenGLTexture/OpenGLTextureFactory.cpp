#include "OpenGLTextureFactory.h"

#include "OpenGLTexture.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	Ref<Texture2D> OpenGLTextureFactory::CreateTexture2D(std::uint32_t width, std::uint32_t height, void* data, std::size_t channelSize)
	{
		return std::make_shared<OpenGLTexture2D>(width, height, data, channelSize);
	}
}
