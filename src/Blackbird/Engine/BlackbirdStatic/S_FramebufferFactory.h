#pragma once

#include "Blackbird/Core/Core.h"
#include "S_Application.h"

#include "Blackbird/Engine/Framebuffer/IFramebufferFactory.h"

namespace Blackbird
{
	class S_FramebufferFactory
	{
	public:
		static Ref<Framebuffer> Create(const FramebufferSpecification& specification) { return S_Application::Engine().FramebufferFactory().Create(specification); }
	};
}

