
#include "OpenGLTexture.h"

#include "glad/glad.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{

	void static GetFormatsFromChannels(std::size_t channelSize, GLenum& internalFormat, GLenum& format)
	{
		if (channelSize == 4)
		{
			internalFormat = GL_RGBA8;
			format = GL_RGBA;
		}
		else if (channelSize == 3)
		{
			internalFormat = GL_RGB8;
			format = GL_RGB;
		}
		else if (channelSize == 2)
		{
			internalFormat = GL_RG;
			format = GL_RG;
		}
		else if (channelSize == 1)
		{
			internalFormat = GL_RED;
			format = GL_RED;
		}
		else
		{
			BLACKBIRD_ASSERT(false, "Unknown picture format for texture");
		}
	}

	OpenGLTexture2D::OpenGLTexture2D(std::uint32_t width, std::uint32_t height, void* data, std::size_t channelSize)
		: m_Width(width)
		, m_Height(height)
	{
		GLenum internalFormat = 0;
		GLenum format = 0;
		GetFormatsFromChannels(channelSize, internalFormat, format);

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, internalFormat, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, format, GL_UNSIGNED_BYTE, data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_RendererID);
	}

	void OpenGLTexture2D::Release(uint32_t slot) const
	{
		glBindTextureUnit(slot, 0);
	}



}
