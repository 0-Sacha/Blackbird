#include "OpenGLGLFWContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Platform/GraphicsPlatform/OpenGL/Utils/OpenGLFormat.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		BLACKBIRD_ASSERT(m_WindowHandle != nullptr, "WindowHandle is null");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BLACKBIRD_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLContext::Destroy()
	{
		glfwDestroyWindow(m_WindowHandle);
	}

	void OpenGLContext::SwapBuffer()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

	void OpenGLContext::DisplayInfo()
	{
		BLACKBIRD_INFO("OpenGl Info :");
		BLACKBIRD_INFO(" - Vendor   : {}", glGetString(GL_VENDOR));
		BLACKBIRD_INFO(" - Renderer : {}", glGetString(GL_RENDERER));
		BLACKBIRD_INFO(" - Version  : {}", glGetString(GL_VERSION));
	}
}
