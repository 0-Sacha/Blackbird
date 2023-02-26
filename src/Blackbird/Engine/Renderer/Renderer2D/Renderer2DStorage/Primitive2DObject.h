#pragma once

#include "Blackbird/Engine/Asset/VertexArray.h"

namespace Blackbird::Renderer2DUtils::Primitive
{

	struct Primitive2DQuad
	{
		Ref<VertexArray> QuadVA;

	public:
		void Init();
		void Release();
	};

}
