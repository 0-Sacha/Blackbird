#pragma once

#include "Platform/GraphicsPlatform/OpenGL/OpenGLCore.h"
#include "Platform/WindowPlatform/GLFW/Context/GLFWContext.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	class OpenGLGLFWContext final : public WindowPlatform::GLFW::IGLFWContext
	{
	public:
		OpenGLGLFWContext(GLFWwindow* windowHandle);
		~OpenGLGLFWContext() override = default;

	public:
		void InitGraphicsPlatform(GLFWContextInitializer proc) override;
		void DisplayInfo() override;
	};
}
