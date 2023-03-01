#pragma once

#include "Blackbird/Core/Core.h"
#include "Shader.h"

namespace Blackbird
{
	class IShaderFactory
	{
	public:
		virtual Ref<Shader> Create(const std::string& name, const Shader::Program& program) = 0;
	
	public:
		Ref<Shader> CreateFromPath(const std::string& path);
		Ref<Shader> CreateFromPaths(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
		Ref<Shader> CreateFromSrcs(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}
