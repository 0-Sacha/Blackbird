#pragma once

#include "Blackbird/Engine/Camera/OrthographicCamera.h"
#include "Blackbird/Engine/Texture/Texture.h"

namespace Blackbird::Renderer2DUtils
{
	struct Renderer2DStorage;
}

namespace Blackbird
{
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

	public:
		static inline Renderer2DUtils::Renderer2DStorage* Storage = nullptr;
	};
}
