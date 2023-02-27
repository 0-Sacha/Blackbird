#pragma once

#include "Blackbird/Engine/Texture/ITextureFactory.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	class OpenGLTextureFactory final : public ITextureFactory
	{
	public:
		Ref<Texture2D> CreateTexture2D(const std::string& path) override;
	};
}
