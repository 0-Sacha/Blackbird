#include "GLFWPlatform.h"

#include "Window/GLFWWindow.h"
#include "Input/GLFWInput.h"

namespace Blackbird::WindowPlatform::GLFW
{
    void GLFWPlatform::InitEngineAPI(EngineAPI& api)
    {
		  api.SetInput(std::make_unique<GLFWInput>());
    }
}
