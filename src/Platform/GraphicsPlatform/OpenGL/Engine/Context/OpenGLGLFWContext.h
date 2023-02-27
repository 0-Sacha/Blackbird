#pragma once

#include "Platform/GraphicsPlatform/OpenGL/OpenGLCore.h"
#include "Platform/WindowPlatform/GLFW/Context/GLFWContext.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	class OpenGLGLFWContext : public WindowPlatform::GLFW::IGLFWContext
	{
	public:
		OpenGLGLFWContext(GLFWwindow* windowHandle);

	public:
		void Init() override;
		void SwapBuffer() override;
		void Destroy() override;

		void DisplayInfo() override;
	};
}
