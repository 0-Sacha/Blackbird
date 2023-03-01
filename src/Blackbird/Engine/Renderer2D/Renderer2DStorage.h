#pragma once

#include "Designer2D/IDesigner2D.h"

#include "Blackbird/Engine/Shader/Shader.h"
#include "Designer2D/QuadDesigner.h"

namespace Blackbird
{
	class Renderer2DStorage
	{
	public:
		Renderer2DStorage(Renderer2D& renderer2D)
			: QuadManager(renderer2D)
		{}

	public:
		QuadDesignerManager QuadManager;

	public:
		void Init()
		{
			QuadManager.Init();
		}

		void Shutdown()
		{}
	};
}
