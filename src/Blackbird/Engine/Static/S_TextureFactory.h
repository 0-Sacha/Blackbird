#pragma once

#include "S_Application.h"

namespace Blackbird
{
	class S_TextureFactory
	{
	public:
		static ITextureFactory& Get() { return S_Application::Engine().TextureFactory(); }

	public:
		static Ref<SpritesPathsLibrary> CreateSpritesPathsLibrary()
		{
			return Get().CreateSpritesPathsLibrary();
		}

	public:
		static Ref<SpritesFactoryLibrary> CreateSpritesFactoryLibraryFromPath(const std::string& path, const glm::uvec2& spriteSize)
		{
			return Get().CreateSpritesFactoryLibraryFromPath(path, spriteSize);
		}

		static Ref<Texture2D> CreateTexture2DFromPath(const std::string& path)	{ return Get().CreateTexture2DFromPath(path); }
		static Ref<Texture2D> CreateTexture2DUniqueColor(std::uint32_t color)	{ return Get().CreateTexture2DUniqueColor(color); }
	};
}
