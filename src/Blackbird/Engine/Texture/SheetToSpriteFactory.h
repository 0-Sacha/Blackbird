#pragma once

#include "SubTexture2D.h"

namespace Blackbird
{

	class SheetToSpriteFactory
	{
	public:
		SheetToSpriteFactory(Ref<Texture2D>& sheetTexture, const glm::uvec2& spriteSize)
			: m_SheetTexture(sheetTexture)
			, m_SpriteSize(spriteSize)
		{}

	public:
		Ref<SubTexture2D> CreateSprite(const glm::uvec2& onSheetIndex, const glm::uvec2& onSheetSize = { 1, 1 });

	protected:
		Ref<Texture2D> m_SheetTexture;
		glm::uvec2 m_SpriteSize;
	};

}
