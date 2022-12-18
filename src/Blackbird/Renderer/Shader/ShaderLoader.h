#pragma once

#include "Shader.h"

namespace Blackbird
{

	class ShaderLoader
	{
	public:
		static std::shared_ptr<Shader> FromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		static std::shared_ptr<Shader> FromGLSLTextFile(const std::string& path);

		static std::shared_ptr<Shader> FromGLSLStrings(const std::string& vertex, const std::string& fragment);
		static std::shared_ptr<Shader> FromGLSLCharPts(const char* const vertex, const char* const fragment);
		static std::shared_ptr<Shader> FromGLSLString(const std::string& source);
	};

}
