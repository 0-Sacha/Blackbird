
#include "Blackbirdpch.h"
#include "Shader.h"

#include "Blackbird/Renderer/Renderer.h"

#include "Platform/OpenGL/Renderer/OpenGLShader/OpenGLShader.h"

namespace Blackbird {

	Ref<Shader> Shader::Create(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
	{
		switch (RendererAPI::GetAPI())
		{
			case RendererAPI::API::None:	BLACKBIRD_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
			case RendererAPI::API::OpenGL:	return std::make_shared<Platform::OpenGL::OpenGLShader>(vertexShaderPath, fragmentShaderPath);
		}

		BLACKBIRD_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

}
