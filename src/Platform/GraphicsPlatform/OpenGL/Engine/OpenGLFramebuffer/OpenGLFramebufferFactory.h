#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Framebuffer/IFramebufferFactory.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	class OpenGLFramebufferFactory final : public IFramebufferFactory
	{
	public:
		Ref<Framebuffer> Create(const FramebufferSpecification& specification) override;
	};
}
