

#include "WindowsInput.h"

#include "Blackbird/EngineDetail/Application/Application.h"
#include <GLFW/glfw3.h>

namespace Blackbird::Platform::Windows
{
	bool WindowsInput::IsKeyPressed(int keyCode)
	{
		auto state = glfwGetKey(GetNativeWindow(), keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseBtPressed(int btCode)
	{
		auto state = glfwGetMouseButton(GetNativeWindow(), btCode);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePosition()
	{
		double xPos, yPos;
		glfwGetCursorPos(GetNativeWindow(), &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	inline GLFWwindow* WindowsInput::GetNativeWindow()
	{
		return static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
	}
}
