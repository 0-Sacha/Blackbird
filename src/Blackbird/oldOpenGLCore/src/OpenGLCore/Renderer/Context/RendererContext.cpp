
#include "OGLCpch.h"
#include "RendererContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "OpenGLCore/Core/OpenGLFormat.h"

namespace OGLC {

	RendererContext::RendererContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		OGLC_ASSERT(m_WindowHandle != nullptr, "WindowHandle is null");
	}

	void RendererContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		OGLC_ASSERT(status, "Failed to initialize Glad!");
	}

	void RendererContext::Destroy()
	{
		glfwDestroyWindow(m_WindowHandle);
	}

	void RendererContext::SwapBuffer()
	{
		glfwSwapBuffers(m_WindowHandle);
	}


	void RendererContext::DisplayInfo()
	{
		OGLC_INFO("OpenGl Info:");
		OGLC_INFO("  Vendor  : {}", glGetString(GL_VENDOR));
		OGLC_INFO("  Renderer: {}", glGetString(GL_RENDERER));
		OGLC_INFO("  Version : {}", glGetString(GL_VERSION));
	}

}






