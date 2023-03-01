#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Context/IRendererContext.h"

struct GLFWwindow;
typedef void* (*GLFWContextInitializer)(const char *name);

namespace Blackbird::WindowPlatform::GLFW
{
	class IGLFWContext : public IRendererContext
	{
	public:
		IGLFWContext(GLFWwindow* windowHandle);

	public:
		void Init() override final;
		void SwapBuffer() override final;
		void Destroy() override final;

		virtual int InitGraphicsPlatform(GLFWContextInitializer proc) = 0;

	protected:
		GLFWwindow* m_WindowHandle;
	};
}
