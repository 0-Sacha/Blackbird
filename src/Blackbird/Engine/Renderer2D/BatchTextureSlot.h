#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Texture/Texture.h"

namespace Blackbird
{
	class BatchTextureSlot
	{
	public:
		using TextureSlotsType = std::unique_ptr<Ref<Texture>>;
		static constexpr std::size_t MAX_TEXTURE_BATCH = 32;

	public:
		BatchTextureSlot(std::size_t maxTextureBatch = MAX_TEXTURE_BATCH)
			: m_TextureSlots(nullptr)
			, m_MaxTexturePerBatch(maxTextureBatch)
			, m_CurrentTextureIndex(0)
		{
			SetSizeAndReset(maxTextureBatch);
		}

	public:
		std::size_t GetMaxTexturePerBatch() const		{ return m_MaxTexturePerBatch; }
		std::size_t GetCurrentNumberOfTexture() const	{ return m_CurrentTextureIndex; }

	protected:
		void SetSizeAndReset(std::size_t maxTextureBatch)
		{
			m_MaxTexturePerBatch = maxTextureBatch;
			if (m_TextureSlots)
				delete[] m_TextureSlots;
			m_TextureSlots = new Ref<Texture>[m_MaxTexturePerBatch];
			m_CurrentTextureIndex = 0;
		}

	public:
		void Reset()
		{
			m_CurrentTextureIndex = 0;
		}

		void BindAllTexture()
		{
			for (std::size_t i = 0; i < m_CurrentTextureIndex; ++i)
				m_TextureSlots[i]->Bind(i);
		}

	public:
		bool AddTexture(Ref<Texture> texture, std::uint32_t& textureIndexBatch)
		{
			for (std::size_t i = 0; i < m_CurrentTextureIndex; ++i)
			{
				Ref<Texture>& slot = m_TextureSlots[i];

				if (slot == nullptr)
					continue;
				if (slot->GetTextureID() == texture->GetTextureID())
				{
					textureIndexBatch = i;
					return true;
				}
			}

			if (m_CurrentTextureIndex + 1 >= m_MaxTexturePerBatch)
				return false;

			textureIndexBatch = m_CurrentTextureIndex;
			m_TextureSlots[m_CurrentTextureIndex++] = texture;
			return true;
		}

	protected:
		std::size_t m_MaxTexturePerBatch;
		std::size_t m_CurrentTextureIndex;

		Ref<Texture>* m_TextureSlots;
	};
}
