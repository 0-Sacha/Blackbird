#include "SheetToSpriteFactory.h"

namespace Blackbird
{

	Ref<SubTexture2D> SheetToSpriteFactory::CreateSprite(const glm::uvec2& onSheetIndex, const glm::uvec2& onSheetSize)
	{
		glm::vec2 texCoordMin = glm::vec2{
			float(onSheetIndex.x * m_SpriteSize.x) / m_SheetTexture->GetWidth(),
			float(onSheetIndex.y * m_SpriteSize.y) / m_SheetTexture->GetHeight()
		};

		glm::vec2 texCoordMax = glm::vec2{
			float((onSheetIndex.x + onSheetSize.x) * m_SpriteSize.x) / m_SheetTexture->GetWidth(),
			float((onSheetIndex.y + onSheetSize.y) * m_SpriteSize.y) / m_SheetTexture->GetHeight()
		};

		return std::make_shared<SubTexture2D>(m_SheetTexture, texCoordMin, texCoordMax, m_SpriteSize.x * onSheetSize.x, m_SpriteSize.y * onSheetSize.y);
	}

}
