#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_Input
	{
	public:
		static IInput& Get() { return StaticContext::Engine().Input(); }

	public:
		inline static bool IsKeyPressed(int keyCode) 				{ return Get().IsKeyPressed(keyCode); }
		inline static bool IsKeyPressed(KeyboardKey key) 			{ return Get().IsKeyPressed(key); }

		inline static bool IsMouseBtPressed(int btCode) 			{ return Get().IsMouseBtPressed(btCode); }
		inline static bool IsMouseBtPressed(MouseBt bt) 			{ return Get().IsMouseBtPressed(bt); }
		inline static std::pair<float, float> GetMousePosition() 	{ return Get().GetMousePosition(); }
		inline static float GetMouseX()								{ return Get().GetMouseX(); };
		inline static float GetMouseY()								{ return Get().GetMouseY(); };
	};
}
