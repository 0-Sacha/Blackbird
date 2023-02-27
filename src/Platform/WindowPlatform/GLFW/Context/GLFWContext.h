#pragma once

#include "Blackbird/Engine/Context/RendererContext.h"

struct GLFWwindow;

namespace Blackbird::WindowPlatform::GLFW
{
	class IGLFWContext : public IRendererContext
	{
	public:
		IGLFWContext(GLFWwindow* windowHandle)
			: m_WindowHandle(windowHandle)
		{}

	protected:
		GLFWwindow* m_WindowHandle;
	};
}
