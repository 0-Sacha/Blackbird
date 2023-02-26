#pragma once

#include "Platform/OpenGL/OpenGLCore.h"
#include "Blackbird/Engine/Texture/Texture.h"

namespace Blackbird::Platform::OpenGL
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& path);
		~OpenGLTexture2D() override;

	public:
		void Bind(uint32_t slot) const override;
		void Release(uint32_t slot) const override;

	public:
		uint32_t GetWidth() const override { return m_Width; }
		uint32_t GetHeight() const override { return m_Height; }

	private:
		std::string m_Path;

		uint32_t m_Width;
		uint32_t m_Height;

		RendererID m_RendererID;
	};
}
