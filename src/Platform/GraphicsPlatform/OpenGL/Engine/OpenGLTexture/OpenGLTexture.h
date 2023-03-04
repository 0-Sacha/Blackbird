#pragma once

#include "Platform/GraphicsPlatform/OpenGL/OpenGLCore.h"
#include "Blackbird/Engine/Texture/Texture.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(std::uint32_t width, std::uint32_t height, void* data, std::size_t channelSize);
		~OpenGLTexture2D() override;

	public:
		void Bind(uint32_t slot) const override;
		void Release(uint32_t slot) const override;

		std::uint32_t GetTextureID() const override { return m_RendererID; }

	public:
		std::uint32_t GetWidth() const override { return m_Width; }
		std::uint32_t GetHeight() const override { return m_Height; }

	private:
		std::uint32_t m_Width;
		std::uint32_t m_Height;

		RendererID m_RendererID;
	};
}
