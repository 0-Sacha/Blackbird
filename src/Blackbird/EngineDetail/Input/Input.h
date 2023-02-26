#pragma once

#include "Blackbird/Core/Core.h"

#include "KeyboardKey.h"
#include "MouseBt.h"

#include "Blackbird/PlatformAPI.h"

namespace Blackbird
{
	class Input
	{
	public:
		inline static bool IsKeyPressed(int keyCode) 				{ return PlatformAPI::GetInstance().GetInput().IsKeyPressed(keyCode); }
		inline static bool IsKeyPressed(KeyboardKey key) 			{ return PlatformAPI::GetInstance().GetInput().IsKeyPressed((int)key); }

		inline static bool IsMouseBtPressed(int btCode) 			{ return PlatformAPI::GetInstance().GetInput().IsMouseBtPressed(btCode); }
		inline static bool IsMouseBtPressed(MouseBt bt) 			{ return PlatformAPI::GetInstance().GetInput().IsMouseBtPressed((int)bt); }
		inline static std::pair<float, float> GetMousePosition() 	{ return PlatformAPI::GetInstance().GetInput().GetMousePosition(); }
		inline static float GetMouseX()								{ return GetMousePosition().first; };
		inline static float GetMouseY()								{ return GetMousePosition().second; };
	};
}
