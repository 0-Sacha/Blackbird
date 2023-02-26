
#include "Shader.h"

#include "Blackbird/Renderer/Renderer.h"

#include "Platform/OpenGL/Renderer/OpenGLShader/OpenGLShader.h"

namespace Blackbird {

	Ref<Shader> Shader::Create(const std::string& name, const Program& program)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	BLACKBIRD_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return Platform::OpenGL::OpenGLShader::Create(name, program);
		}

		BLACKBIRD_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}
}
