#include "Blackbirdpch.h"
#include "Primitive2DShader.h"

#include "Blackbird/Renderer/Shader/ShaderFactory.h"

namespace Blackbird::Renderer2DUtils::Primitive
{

	void Primitive2DShaders::Init()
	{
		FlatColorShader = ShaderFactory::CreateFromPath("assets/shaders/FlatColor.glsl");
		TextureShader = ShaderFactory::CreateFromPath("assets/shaders/Texture.glsl");
		TextureShader->Bind();
		TextureShader->SetInt("u_Texture", 0);
	}

	void Primitive2DShaders::Release()
	{

	}

}
