#include "Framebuffer.h"

namespace Blackbird
{

	void Framebuffer::Resize(std::uint32_t width, std::uint32_t height)
	{
		if (width == m_Specification.Width && height == m_Specification.Height)
			return;

		static constexpr std::uint32_t s_MaxSize = 8192; // TODO : Renderer Capability

		if (width == 0 || height == 0 || width > s_MaxSize || height > s_MaxSize)
		{
			BLACKBIRD_WARN("Coundn't set size for framebuffers = 0 ; width, heigth = {}, {} ", width, height);
			return;
		}
		m_Specification.Width = width;
		m_Specification.Height = height;
		Invalidate();
	}

}
