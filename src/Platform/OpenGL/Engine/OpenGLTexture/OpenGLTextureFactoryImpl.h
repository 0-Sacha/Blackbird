#pragma once

#include "Blackbird/Engine/Texture/TextureFactoryImpl.h"

namespace Blackbird::Platform::OpenGL
{
	class OpenGLTextureFactoryImpl final : public TextureFactoryImpl
	{
	public:
		Ref<Texture2D> CreateTexture2D(const std::string& path) override;
	};
}
