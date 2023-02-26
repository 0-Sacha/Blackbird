#pragma once

#include "Blackbird/Core/Core.h"
#include "Shader.h"

namespace Blackbird
{
	class ShaderFactoryImpl
	{
	public:
		virtual Ref<Shader> Create(const std::string& name, const Shader::Program& program) = 0;
	};
}
