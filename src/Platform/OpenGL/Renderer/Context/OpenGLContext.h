#pragma once

#include "Platform/OpenGL/OpenGLCore.h"

#include "Blackbird/Renderer/Context/RendererContext.h"

struct GLFWwindow;

namespace Blackbird::Platform::OpenGL
{

	class OpenGLContext : public RendererContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		void Init() override;
		void SwapBuffer() override;
		void Destroy() override;

		void DisplayInfo() override;

	private:
		GLFWwindow* m_WindowHandle;
	};

}