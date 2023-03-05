#pragma once

#include "Blackbird/Core/Core.h"
#include "Framebuffer.h"

namespace Blackbird
{
	class IFramebufferFactory
	{
	public:
		virtual Ref<Framebuffer> Create(const FramebufferSpecification& specification) = 0;
	};
}
