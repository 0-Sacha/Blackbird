#pragma once

#include "SubTexture2D.h"

#include "SheetToSpriteFactory.h"

namespace Blackbird
{
	class ITextureFactory;

	class SpritesLibrary
	{
	public:
		virtual ~SpritesLibrary() = default;

	public:
		bool Exists(const std::string& name);
		Ref<Texture2D> Get(const std::string& name);
		void Add(const std::string& name, const Ref<Texture2D>& sprite);

	protected:
		std::unordered_map<std::string, Ref<Texture2D>> m_Sprites;
	};

	class SpritesPathsLibrary : public SpritesLibrary
	{
	public:
		SpritesPathsLibrary(ITextureFactory& factory)
			: m_TextureFactory(factory)
		{}

		~SpritesPathsLibrary() override = default;

	protected:
		using SpritesLibrary::Add;

	public:
		Ref<Texture2D> LoadFromPath(const std::string& name, const std::string& path);

	protected:
		ITextureFactory& m_TextureFactory;
	};

	class SpritesFactoryLibrary : public SpritesLibrary
	{
	public:
		SpritesFactoryLibrary(Ref<SheetToSpriteFactory>& factory)
			: m_SheetToSpriteFactory(factory)
		{}

		~SpritesFactoryLibrary() override = default;

	protected:
		using SpritesLibrary::Add;

	public:
		Ref<Texture2D> AddSprite(const std::string& name, const glm::uvec2& onSheetIndex, const glm::uvec2& onSheetSize = { 1, 1 });

	protected:
		Ref<SheetToSpriteFactory> m_SheetToSpriteFactory;
	};

}
