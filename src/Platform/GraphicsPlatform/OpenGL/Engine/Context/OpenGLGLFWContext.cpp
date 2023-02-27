#include "OpenGLGLFWContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Platform/GraphicsPlatform/OpenGL/Utils/OpenGLFormat.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	OpenGLGLFWContext::OpenGLGLFWContext(GLFWwindow* windowHandle)
		: WindowPlatform::GLFW::IGLFWContext(windowHandle)
	{
		BLACKBIRD_ASSERT(m_WindowHandle != nullptr, "WindowHandle is null");
	}

	void OpenGLGLFWContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BLACKBIRD_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLGLFWContext::Destroy()
	{
		glfwDestroyWindow(m_WindowHandle);
	}

	void OpenGLGLFWContext::SwapBuffer()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

	void OpenGLGLFWContext::DisplayInfo()
	{
		BLACKBIRD_INFO("OpenGl Info :");
		BLACKBIRD_INFO(" - Vendor   : {}", glGetString(GL_VENDOR));
		BLACKBIRD_INFO(" - Renderer : {}", glGetString(GL_RENDERER));
		BLACKBIRD_INFO(" - Version  : {}", glGetString(GL_VERSION));
	}
}
