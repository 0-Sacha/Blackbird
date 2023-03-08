#pragma once

#include "Blackbird/Core/Core.h"
#include "Texture.h"
#include "SubTexture2D.h"
#include "SheetToSpriteFactory.h"
#include "SpritesLibrary.h"

#include <string>

namespace Blackbird
{
	class ITextureFactory
	{
	public:
		virtual ~ITextureFactory() = default;

	public:
		virtual Ref<Texture2D> CreateTexture2D(std::uint32_t width, std::uint32_t height, void* data, std::size_t channelSize) = 0;
	
	public:
		Ref<SpritesPathsLibrary> CreateSpritesPathsLibrary() { return std::make_shared<SpritesPathsLibrary>(*this); }
	
	public:
		Ref<SpritesFactoryLibrary> CreateSpritesFactoryLibraryFromPath(const std::string& path, const glm::uvec2& spriteSize);

		Ref<Texture2D> CreateTexture2DFromPath(const std::string& path);
		Ref<Texture2D> CreateTexture2DUniqueColor(std::uint32_t color);
	};
}
