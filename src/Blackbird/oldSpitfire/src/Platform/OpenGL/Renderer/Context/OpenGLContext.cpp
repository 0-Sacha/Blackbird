
#include "Spitfirepch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Platform/OpenGL/Utils/OpenGLFormat.h"

namespace Spitfire {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SPITFIRE_ASSERT(m_WindowHandle != nullptr, "WindowHandle is null");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SPITFIRE_ASSERT(status, "Failed to initialize Glad!");
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
		SPITFIRE_INFO("OpenGl Info :");
		SPITFIRE_INFO(" - Vendor   : {}", glGetString(GL_VENDOR));
		SPITFIRE_INFO(" - Renderer : {}", glGetString(GL_RENDERER));
		SPITFIRE_INFO(" - Version  : {}", glGetString(GL_VERSION));
	}

}