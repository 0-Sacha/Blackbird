#pragma once

#include "Blackbird/Engine/Framebuffer/Framebuffer.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{

	class OpenGLFramebuffer final : public Framebuffer
	{
	public:
		OpenGLFramebuffer(const FramebufferSpecification& specification)
			: Framebuffer(specification)
			, m_RendererID(0)
			, m_ColorAttachmentID(0)
			, m_DepthAttachmentID(0)
		{
			Invalidate();
		}

		~OpenGLFramebuffer() override
		{ 
			Destroy();
		}

	public:
		void Invalidate() override;
		void Destroy();

	public:
		void Bind() const override;
		void Release() const override;

	public:
		std::uint32_t GetColorAttachementID() const override { return m_ColorAttachmentID; }

	private:
		OpenGLRendererID m_RendererID;

		OpenGLRendererID m_ColorAttachmentID;
		OpenGLRendererID m_DepthAttachmentID;
	};

}
