#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_TextureFactory
	{
	public:
		static Ref<Texture2D> CreateTexture2DFromPath(const std::string& path)	{ return StaticContext::Engine().TextureFactory().CreateTexture2DFromPath(path); }
		static Ref<Texture2D> CreateTexture2DUniqueColor(std::uint32_t color)	{ return StaticContext::Engine().TextureFactory().CreateTexture2DUniqueColor(color); }
	};
}
