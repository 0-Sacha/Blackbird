#pragma once
#include "OpenGLShaderFactoryImpl.h"

#include "OpenGLShader.h"

namespace Blackbird::Platform::OpenGL
{
	Ref<Shader> OpenGLShaderFactoryImpl::Create(const std::string& name, const Shader::Program& program)
	{
		return std::make_shared<OpenGLShader>(name, OpenGLShader::LinkShader(program));
	}
}
