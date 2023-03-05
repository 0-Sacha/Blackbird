#pragma once

#include "Blackbird/Core/Core.h"
#include "Platform/GraphicsPlatform/OpenGL/OpenGLCore.h"

namespace Blackbird
{

	struct FramebufferSpecification
	{
		std::uint32_t Width = 1080;
		std::uint32_t Height = 720;

		std::uint32_t Samples = 1;

		bool SwapChainTarget = false;
	};

	class Framebuffer
	{
	public:
		Framebuffer(const FramebufferSpecification& specification)
			: m_Specification(specification)
		{}

		virtual ~Framebuffer()
		{
			Destroy();
		}

	public:
		const FramebufferSpecification& GetSpecification()						{ return m_Specification; }
		void SetSpecification(const FramebufferSpecification& specification)	{ m_Specification = specification; Invalidate(); }

		void Resize(std::uint32_t width, std::uint32_t height);

	public:
		virtual void Bind() const = 0;
		virtual void Release() const = 0;

	public:
		virtual std::uint32_t GetColorAttachementID() const = 0;
	
	public:
		std::uint32_t GetWidth() const		{ return m_Specification.Width; }
		std::uint32_t GetHeight() const		{ return m_Specification.Height; }

	protected:
		virtual void Invalidate() = 0;
		virtual void Destroy() {}

	protected:
		FramebufferSpecification m_Specification;
	};

}
