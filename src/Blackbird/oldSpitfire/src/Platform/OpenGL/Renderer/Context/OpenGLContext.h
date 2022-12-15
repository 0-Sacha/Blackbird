#pragma once

#include "Spitfire/Core/Core.h"

#include "Spitfire/Renderer/Context/RendererContext.h"

struct GLFWwindow;

namespace Spitfire {

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