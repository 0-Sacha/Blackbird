#pragma once

#include "Blackbird/Engine/Renderer/Renderer2D/Renderer2DStorage/Primitive2DShader.h"
#include "Blackbird/Engine/Renderer/Renderer2D/Renderer2DStorage/Primitive2DObject.h"

namespace Blackbird::Renderer2DUtils
{
	struct Renderer2DStorage
	{
	public:
		Primitive::Primitive2DQuad Quad2D;
		Primitive::Primitive2DShaders Shaders;

	public:
		void Init();
		void Release();
	};
}
