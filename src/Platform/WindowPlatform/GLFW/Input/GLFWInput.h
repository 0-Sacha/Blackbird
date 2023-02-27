#pragma once

#include "Blackbird/EngineDetail/Input/IInput.h"

struct GLFWwindow;

namespace Blackbird::WindowPlatform::GLFW
{
	class GLFWInput : public IInput
	{
	public:
		bool IsKeyPressed(int keyCode) override;
		bool IsMouseBtPressed(int btCode) override;
		std::pair<float, float> GetMousePosition() override;

	private:
		inline GLFWwindow* GetNativeWindow();
	};
}
