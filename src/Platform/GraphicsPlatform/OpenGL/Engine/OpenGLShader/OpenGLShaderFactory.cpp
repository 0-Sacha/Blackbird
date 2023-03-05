#include "OpenGLShaderFactory.h"

#include "OpenGLShader.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	Ref<Shader> OpenGLShaderFactory::Create(const std::string& name, const Shader::Program& program)
	{
		return std::make_shared<OpenGLShader>(name, OpenGLShader::LinkShader(program));
	}
}
