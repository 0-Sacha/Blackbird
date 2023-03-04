#pragma once

#include "Blackbird/EngineDetail/Input/IInput.h"
#include "Blackbird/EngineDetail/Window.h"

namespace Blackbird::WindowPlatform::GLFW
{
	class GLFWInput : public IInput
	{
	public:
		GLFWInput(Ref<Window>& window)
			: m_Window(window)
		{}
	
	public:
		bool IsKeyPressed(int keyCode) override;
		bool IsMouseBtPressed(int btCode) override;
		std::pair<float, float> GetMousePosition() override;

	private:
		Ref<Window> m_Window;
	};
}
