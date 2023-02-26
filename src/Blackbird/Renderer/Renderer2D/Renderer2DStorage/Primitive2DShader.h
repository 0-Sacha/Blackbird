#pragma once

#include "Blackbird/Renderer/Shader/Shader.h"

namespace Blackbird::Renderer2DUtils::Primitive
{

	struct Primitive2DShaders
	{
		Ref<Shader> FlatColorShader;
		Ref<Shader> TextureShader;

	public:
		void Init();
		void Release();
	};

}
