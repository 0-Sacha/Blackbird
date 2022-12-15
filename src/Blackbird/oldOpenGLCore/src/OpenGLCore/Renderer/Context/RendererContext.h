#pragma once

#include "OpenGLCore/Core/Core.h"

struct GLFWwindow;

namespace OGLC {

	class RendererContext
	{
	public:
		RendererContext(GLFWwindow* windowHandle);

		void Init();
		void SwapBuffer();
		void Destroy();

		void DisplayInfo();

	private:
		GLFWwindow* m_WindowHandle;
	};

}