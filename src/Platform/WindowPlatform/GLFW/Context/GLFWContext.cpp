#include "GLFWContext.h"

#include <GLFW/glfw3.h>

namespace Blackbird::WindowPlatform::GLFW
{
	IGLFWContext::IGLFWContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		BLACKBIRD_ASSERT(m_WindowHandle != nullptr, "WindowHandle is null");
	}

	void IGLFWContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = InitGraphicsPlatform((GLFWContextInitializer)glfwGetProcAddress);
		BLACKBIRD_ASSERT(status, "Failed to initialize Glad!");
	}

	void IGLFWContext::Destroy()
	{
		glfwDestroyWindow(m_WindowHandle);
	}

	void IGLFWContext::SwapBuffer()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
