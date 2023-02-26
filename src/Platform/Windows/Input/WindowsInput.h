#pragma once

#include "Blackbird/EngineDetail/Input/InputImpl.h"

struct GLFWwindow;

namespace Blackbird::Platform::Windows
{
	class WindowsInput : public InputImpl
	{
	public:
		bool IsKeyPressed(int keyCode) override;
		bool IsMouseBtPressed(int btCode) override;
		std::pair<float, float> GetMousePosition() override;

	private:
		inline GLFWwindow* GetNativeWindow();
	};
}
