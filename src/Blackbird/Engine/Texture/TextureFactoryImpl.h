#pragma once

#include "Blackbird/Core/Core.h"
#include "Texture.h"

namespace Blackbird
{
	class TextureFactoryImpl
	{
	public:
		virtual Ref<Texture2D> CreateTexture2D(const std::string& path) = 0;
	};
}
