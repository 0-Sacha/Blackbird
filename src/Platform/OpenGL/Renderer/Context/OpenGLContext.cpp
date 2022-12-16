
#include "Blackbirdpch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Platform/OpenGL/Utils/OpenGLFormat.h"

namespace Blackbird {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		BlACKBIRD_ASSERT(m_WindowHandle != nullptr, "WindowHandle is null");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BlACKBIRD_ASSERT(status, "Failed to initialize Glad!");
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
		BlACKBIRD_INFO("OpenGl Info :");
		BlACKBIRD_INFO(" - Vendor   : {}", glGetString(GL_VENDOR));
		BlACKBIRD_INFO(" - Renderer : {}", glGetString(GL_RENDERER));
		BlACKBIRD_INFO(" - Version  : {}", glGetString(GL_VERSION));
	}

}