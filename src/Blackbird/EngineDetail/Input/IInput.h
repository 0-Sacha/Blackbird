#pragma once

#include "Blackbird/Core/Core.h"

#include "KeyboardKey.h"
#include "MouseBt.h"

namespace Blackbird
{
	class IInput
	{
	public:
		virtual ~IInput() = default;

	public:
		virtual bool IsKeyPressed(int keycode) = 0;

		virtual bool IsMouseBtPressed(int btCode) = 0;
		virtual std::pair<float, float> GetMousePosition() = 0;

	public:
		bool IsKeyPressed(KeyboardKey key)	{ return IsKeyPressed((int)key); }
		bool IsMouseBtPressed(MouseBt bt)	{ return IsMouseBtPressed((int)bt); }

		float GetMouseX() { return GetMousePosition().first; };
		float GetMouseY() { return GetMousePosition().second; };
	};
}
