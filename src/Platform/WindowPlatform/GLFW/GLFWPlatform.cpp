#include "GLFWPlatform.h"

#include "Window/GLFWWindow.h"
#include "Input/GLFWInput.h"

namespace Blackbird::WindowPlatform::GLFW
{
    void GLFWPlatform::InitEngineAPI(EngineAPI& api)
    {
		api.SetInput(CreateScope<GLFWInput>());
    }

    Scope<Window> GLFWPlatform::CreateWindow(const WindowProps& props, PlatformAPI& api)
    {
        return std::make_unique<GLFWWindow>(props, api);
    }
}
