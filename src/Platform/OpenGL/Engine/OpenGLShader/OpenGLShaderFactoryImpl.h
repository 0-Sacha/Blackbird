#pragma once

#include "Blackbird/Engine/Shader/ShaderFactoryImpl.h"

namespace Blackbird::Platform::OpenGL
{
	class OpenGLShaderFactoryImpl final : public ShaderFactoryImpl
	{
	public:
		Ref<Shader> Create(const std::string& name, const Shader::Program& program) override;
	};
}
