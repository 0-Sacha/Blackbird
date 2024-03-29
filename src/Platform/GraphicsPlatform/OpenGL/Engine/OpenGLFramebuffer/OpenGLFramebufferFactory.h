#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Framebuffer/IFramebufferFactory.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{
	class OpenGLFramebufferFactory final : public IFramebufferFactory
	{
	public:
		~OpenGLFramebufferFactory() override = default;
	
	public:
		Ref<Framebuffer> Create(const FramebufferSpecification& specification) override;
	};
}
