#include "GLFWPlatform.h"

#include "Window/GLFWWindow.h"
#include "Input/GLFWInput.h"
#include "ImGui/GLFWImGuiPlatform.h"

#include <GLFW/glfw3.h>

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

	Scope<ImGuiLayer::IImGuiWindowPlatform> GLFWPlatform::CreateImGuiWindowPlatform()
	{
		return std::make_unique<GLFWImGuiPlatform>();
	}

	float GLFWPlatform::GetTime()
	{
        return glfwGetTime();
	}

}
