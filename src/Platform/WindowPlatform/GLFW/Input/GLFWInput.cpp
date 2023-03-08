#include "GLFWInput.h"

#include "Blackbird/EngineDetail/Application/Application.h"
#include <GLFW/glfw3.h>

namespace Blackbird::WindowPlatforms::GLFW
{

	bool GLFWInput::IsKeyPressed(int keyCode)
	{
		auto state = glfwGetKey((GLFWwindow*)m_Window->GetNativeWindow(), keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool GLFWInput::IsMouseBtPressed(int btCode)
	{
		auto state = glfwGetMouseButton((GLFWwindow*)m_Window->GetNativeWindow(), btCode);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> GLFWInput::GetMousePosition()
	{
		double xPos, yPos;
		glfwGetCursorPos((GLFWwindow*)m_Window->GetNativeWindow(), &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

}
