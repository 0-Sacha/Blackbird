#pragma once

#include "Blackbird/Engine/Texture/ITextureFactory.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	class OpenGLTextureFactory final : public ITextureFactory
	{
	public:
		~OpenGLTextureFactory() override = default;

	public:
		Ref<Texture2D> CreateTexture2D(std::uint32_t width, std::uint32_t height, void* data, std::size_t channelSize) override;
	};
}
