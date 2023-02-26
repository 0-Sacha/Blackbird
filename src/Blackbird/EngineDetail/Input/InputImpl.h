#pragma once

#include "Blackbird/Core/Core.h"

#include "KeyboardKey.h"
#include "MouseBt.h"

namespace Blackbird
{
	class InputImpl
	{
	public:
		virtual bool IsKeyPressed(int keycode) = 0;
		virtual bool IsMouseBtPressed(int btCode) = 0;
		virtual std::pair<float, float> GetMousePosition() = 0;
	};
}
