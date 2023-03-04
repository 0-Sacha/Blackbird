#include "SpritesLibrary.h"

#include "ITextureFactory.h"

namespace Blackbird
{

	bool SpritesLibrary::Exists(const std::string& name)
	{
		return m_Sprites.find(name) != m_Sprites.end();
	}

	void SpritesLibrary::Add(const std::string& name, const Ref<Texture2D>& sprite)
	{
		BLACKBIRD_ASSERT(!Exists(name), "Sprite {} already exist", name);
		m_Sprites[name] = sprite;
	}

	Ref<Texture2D> SpritesLibrary::Get(const std::string& name)
	{
		BLACKBIRD_ASSERT(Exists(name), "Shader {} doesn't exist", name);
		return m_Sprites[name];
	}


	Ref<Texture2D> SpritesPathsLibrary::LoadFromPath(const std::string& name, const std::string& path)
	{
		Ref<Texture2D> sprite = m_TextureFactory.CreateTexture2DFromPath(path);
		Add(name, sprite);
		return sprite;
	}


	Ref<Texture2D> SpritesFactoryLibrary::AddSprite(const std::string& name, const glm::uvec2& onSheetIndex, const glm::uvec2& onSheetSize)
	{
		Ref<Texture2D> sprite = m_SheetToSpriteFactory->CreateSprite(onSheetIndex, onSheetSize);
		Add(name, sprite);
		return sprite;
	}

}
