#pragma once

#include "Blackbird/Core/Core.h"
#include "Texture.h"

#include <string>

namespace Blackbird
{
	class ITextureFactory
	{
	public:
		virtual Ref<Texture2D> CreateTexture2D(std::uint32_t width, std::uint32_t height, void* data, std::size_t channelSize) = 0;
	
	public:
		Ref<Texture2D> CreateTexture2DFromPath(const std::string& path);
		Ref<Texture2D> CreateTexture2DUniqueColor(std::uint32_t color);
	};
}
