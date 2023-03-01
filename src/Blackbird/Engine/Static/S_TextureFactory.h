#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_TextureFactory
	{
	public:
		static Ref<Texture2D> CreateTexture2D(const std::string& path) { return StaticContext::Engine().TextureFactory().CreateTexture2D(path); }
	};
}
