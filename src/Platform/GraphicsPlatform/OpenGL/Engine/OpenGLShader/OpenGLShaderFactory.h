#pragma once

#include "Blackbird/Engine/Shader/IShaderFactory.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	class OpenGLShaderFactory final : public IShaderFactory
	{
	public:
		~OpenGLShaderFactory() override = default;

	public:
		Ref<Shader> Create(const std::string& name, const Shader::Program& program) override;
	};
}
