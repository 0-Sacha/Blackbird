
#include "Blackbirdpch.h"

#include "WindowsInput.h"

#include "Blackbird/Core/Application/Application.h"
#include <GLFW/glfw3.h>

namespace Blackbird {

	Input* Input::GetInstance() {
		Input* instance = new WindowsInput();
		return instance;
	}

	bool WindowsInput::IsKeyPressedImpl(int keyCode)
	{
		auto state = glfwGetKey(GetNativeWindow(), keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseBtPressedImpl(int btCode)
	{
		auto state = glfwGetMouseButton(GetNativeWindow(), btCode);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		double xPos, yPos;
		glfwGetCursorPos(GetNativeWindow(), &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}

	inline GLFWwindow* WindowsInput::GetNativeWindow()
	{
		return static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
	}

}