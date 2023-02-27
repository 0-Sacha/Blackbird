

#include "GLFWInput.h"

#include "Blackbird/EngineDetail/Application/Application.h"
#include <GLFW/glfw3.h>

namespace Blackbird::WindowPlatform::GLFW
{
	bool GLFWInput::IsKeyPressed(int keyCode)
	{
		auto state = glfwGetKey(GetNativeWindow(), keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool GLFWInput::IsMouseBtPressed(int btCode)
	{
		auto state = glfwGetMouseButton(GetNativeWindow(), btCode);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> GLFWInput::GetMousePosition()
	{
		double xPos, yPos;
		glfwGetCursorPos(GetNativeWindow(), &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	inline GLFWwindow* GLFWInput::GetNativeWindow()
	{
		return static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
	}
}
