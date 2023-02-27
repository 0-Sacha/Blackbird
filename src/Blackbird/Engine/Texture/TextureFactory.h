#pragma once

#include "Blackbird/Core/Core.h"
#include "Texture.h"

#include "Blackbird/EngineAPI.h"

namespace Blackbird
{
	class TextureFactory
	{
	public:
		static Ref<Texture2D> CreateTexture2D(const std::string& path) { return EngineAPI::GetInstance().GetTextureFactory().CreateTexture2D(path); }
	};
}
