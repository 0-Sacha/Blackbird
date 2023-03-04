#include "ITextureFactory.h"

#include "stb_image.h"

namespace Blackbird
{

	Ref<SpritesFactoryLibrary> ITextureFactory::CreateSpritesFactoryLibraryFromPath(const std::string& path, const glm::uvec2& spriteSize)
	{
		Ref<Texture2D> sheetTexture = CreateTexture2DFromPath(path);
		Ref<SheetToSpriteFactory> factory = std::make_shared<SheetToSpriteFactory>(sheetTexture, spriteSize);
		return std::make_shared<SpritesFactoryLibrary>(factory);
	}

	Ref<Texture2D> ITextureFactory::CreateTexture2DFromPath(const std::string& path)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);

		Ref<Texture2D> res = CreateTexture2D(width, height, data, channels);

		stbi_image_free(data);

		return res;
	}

	Ref<Texture2D> ITextureFactory::CreateTexture2DUniqueColor(std::uint32_t color)
	{
		return CreateTexture2D(1, 1, &color, sizeof(std::uint32_t));
	}

}
