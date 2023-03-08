#pragma once

#include "Texture.h"

#include <unordered_map>
#include <string>

namespace Blackbird
{

	class SubTexture2D : public Texture2D
	{
	public:
		SubTexture2D(Ref<Texture2D>& texture, const glm::vec2& texCoordMin, const glm::vec2& texCoordMax, std::uint32_t width, std::uint32_t height)
			: m_SheetTexture(texture)
			, m_TexCoordMin(texCoordMin)
			, m_TexCoordMax(texCoordMax)
			, m_SubTextureWidth(width)
			, m_SubTextureHeight(height)
		{}

		~SubTexture2D() override = default;

	public:
		void Bind(uint32_t slot = 0) const override { return m_SheetTexture->Bind(); }
		void Release(uint32_t slot = 0) const override { return m_SheetTexture->Release(); }
		std::uint32_t GetTextureID() const override { return m_SheetTexture->GetTextureID(); }

	public:
		uint32_t GetWidth() const override { return m_SubTextureWidth; }
		uint32_t GetHeight() const override { return m_SubTextureHeight; }
	
		glm::vec2 GetTexCoordsMin() const override { return m_TexCoordMin; }
		glm::vec2 GetTexCoordsMax() const override { return m_TexCoordMax; }

	protected:
		Ref<Texture2D> m_SheetTexture;
		glm::vec2 m_TexCoordMin;
		glm::vec2 m_TexCoordMax;
		std::uint32_t m_SubTextureWidth;
		std::uint32_t m_SubTextureHeight;
	};

}
