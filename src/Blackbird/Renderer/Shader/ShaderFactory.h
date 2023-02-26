#pragma once

#include "Blackbird/Core/Core.h"
#include "Shader.h"

namespace Blackbird
{

	class ShaderFactory
	{
	public:
		static Ref<Shader> CreateFromPath(const std::string& path);
		static Ref<Shader> CreateFromPaths(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
		static Ref<Shader> CreateFromSrcs(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}
