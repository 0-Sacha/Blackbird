#pragma once

#include "Blackbird/Core/Core.h"

#include "Blackbird/Renderer/Context/RendererContext.h"

struct GLFWwindow;

namespace Blackbird {

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