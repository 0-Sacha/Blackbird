#include "OpenGLFramebufferFactory.h"

#include "OpenGLFramebuffer.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{
	Ref<Framebuffer> OpenGLFramebufferFactory::Create(const FramebufferSpecification& specification)
	{
		return std::make_shared<OpenGLFramebuffer>(specification);
	}
}
