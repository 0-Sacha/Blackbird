#include "GLFWPlatform.h"

#include "Window/GLFWWindow.h"
#include "Input/GLFWInput.h"

#include "GLFWImGuiInclude.h"
#include "GLFWInclude.h"

namespace Blackbird::WindowPlatform::GLFW
{
    void GLFWPlatform::InitEngineAPI(EngineAPI& api, Ref<Window>& window)
    {
        api.SetInput(std::make_unique<GLFWInput>(window));
    }

    Ref<Window> GLFWPlatform::CreateWindow(const WindowProps& props, PlatformAPI& api)
    {
        return std::make_shared<GLFWWindow>(props, api);
    }

	void GLFWPlatform::ImGUIInit(Window& window)
	{
		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)window.GetNativeWindow(), true);
	}

	void GLFWPlatform::ImGUIShutdown()
	{
		ImGui_ImplGlfw_Shutdown();
	}

	void GLFWPlatform::ImGUINewFrame()
	{
		ImGui_ImplGlfw_NewFrame();
	}

	void GLFWPlatform::ImGuiViewportPass()
	{
		GLFWwindow* backupCurrentContext = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backupCurrentContext);
	}

}
