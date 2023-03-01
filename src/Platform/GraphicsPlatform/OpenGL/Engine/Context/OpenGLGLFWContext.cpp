#include "OpenGLGLFWContext.h"

#include <glad/glad.h>

#include "Platform/GraphicsPlatform/OpenGL/Utils/OpenGLFormat.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	OpenGLGLFWContext::OpenGLGLFWContext(GLFWwindow* windowHandle)
		: WindowPlatform::GLFW::IGLFWContext(windowHandle)
	{
		BLACKBIRD_ASSERT(m_WindowHandle != nullptr, "WindowHandle is null");
	}

	int OpenGLGLFWContext::InitGraphicsPlatform(GLFWContextInitializer proc)
	{
		return gladLoadGLLoader((GLADloadproc)proc);
	}

	void OpenGLGLFWContext::DisplayInfo()
	{
		BLACKBIRD_INFO("OpenGl Info :");
		BLACKBIRD_INFO(" - Vendor   : {}", glGetString(GL_VENDOR));
		BLACKBIRD_INFO(" - Renderer : {}", glGetString(GL_RENDERER));
		BLACKBIRD_INFO(" - Version  : {}", glGetString(GL_VERSION));
	}
}
