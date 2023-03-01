#pragma once

#include "Designer2D/IDesigner2D.h"

#include "Blackbird/Engine/Shader/Shader.h"
#include "Designer2D/QuadDesigner.h"

namespace Blackbird
{
	struct Renderer2DStorage
	{
	public:
		QuadDesignerManager QuadManager;

	public:
		void Init(Renderer2D& renderer);
		void Release();
	};
}
