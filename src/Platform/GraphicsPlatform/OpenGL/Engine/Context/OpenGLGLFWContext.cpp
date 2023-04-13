#include "OpenGLGLFWContext.h"

#include "glad/glad.h"

#include "Platform/GraphicsPlatform/OpenGL/Utils/OpenGLFormat.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{
	OpenGLGLFWContext::OpenGLGLFWContext(GLFWwindow* windowHandle)
		: WindowPlatforms::GLFW::IGLFWContext(windowHandle)
	{
		BLACKBIRD_ASSERT(m_WindowHandle != nullptr, "WindowHandle is null");
	}

	void OpenGLGLFWContext::InitGraphicsPlatform(GLFWContextInitializer proc)
	{
		int status = gladLoadGLLoader((GLADloadproc)proc);
		BLACKBIRD_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLGLFWContext::DisplayInfo()
	{
		BLKBID_INFO("OpenGl Info :");
		BLKBID_INFO(" - Vendor   : {}", glGetString(GL_VENDOR));
		BLKBID_INFO(" - Renderer : {}", glGetString(GL_RENDERER));
		BLKBID_INFO(" - Version  : {}", glGetString(GL_VERSION));
	}
}
