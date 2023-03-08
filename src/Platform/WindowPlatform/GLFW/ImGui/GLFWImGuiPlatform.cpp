#include "GLFWImGuiPlatform.h"

#include <GLFW/glfw3.h>
#include "backends/imgui_impl_glfw.h"

namespace Blackbird::WindowPlatform::GLFW
{

	void GLFWImGuiPlatform::InitImpl(Window& window)
	{
		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)window.GetNativeWindow(), true);
	}

	void GLFWImGuiPlatform::ShutdownImpl()
	{
		ImGui_ImplGlfw_Shutdown();
	}

	void GLFWImGuiPlatform::NewFrameImpl()
	{
		ImGui_ImplGlfw_NewFrame();
	}

	void GLFWImGuiPlatform::ViewportPassImpl()
	{
		GLFWwindow* backupCurrentContext = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backupCurrentContext);
	}

}
