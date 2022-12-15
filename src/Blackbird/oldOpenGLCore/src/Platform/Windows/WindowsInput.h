#pragma once

#include "OpenGlCore/Core/Input/Input.h"

struct GLFWwindow;

namespace OGLC {

	class WindowsInput : public Input
	{
	protected:
		bool IsKeyPressedImpl(int keyCode) override;

		bool IsMouseBtPressedImpl(int btCode) override;
		std::pair<float, float> GetMousePositionImpl() override;
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;

	private:
		inline GLFWwindow* GetNativeWindow();
	};

}