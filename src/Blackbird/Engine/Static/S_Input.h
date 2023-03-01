#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_Input
	{
	public:
		inline static bool IsKeyPressed(int keyCode) 				{ return StaticContext::Engine().Input().IsKeyPressed(keyCode); }
		inline static bool IsKeyPressed(KeyboardKey key) 			{ return StaticContext::Engine().Input().IsKeyPressed((int)key); }

		inline static bool IsMouseBtPressed(int btCode) 			{ return StaticContext::Engine().Input().IsMouseBtPressed(btCode); }
		inline static bool IsMouseBtPressed(MouseBt bt) 			{ return StaticContext::Engine().Input().IsMouseBtPressed((int)bt); }
		inline static std::pair<float, float> GetMousePosition() 	{ return StaticContext::Engine().Input().GetMousePosition(); }
		inline static float GetMouseX()								{ return StaticContext::Engine().Input().GetMouseX(); };
		inline static float GetMouseY()								{ return StaticContext::Engine().Input().GetMouseY(); };
	};
}
