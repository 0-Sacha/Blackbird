
#include "Blackbirdpch.h"
#include "ShaderLoader.h"

namespace Blackbird
{
	std::shared_ptr<Shader> ShaderLoader::FromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
	{
		std::shared_ptr<Shader> shader = std::make_shared<Shader>();
		shader->LoadGLSLTextFiles(vertexShaderPath, fragmentShaderPath);
		return shader;
	}

	std::shared_ptr<Shader> ShaderLoader::FromGLSLTextFile(const std::string& path)
	{
		std::shared_ptr<Shader> shader = std::make_shared<Shader>();
		shader->LoadGLSLTextFile(path);
		return shader;
	}

	std::shared_ptr<Shader> ShaderLoader::FromGLSLStrings(const std::string& vertex, const std::string& fragment)
	{
		std::shared_ptr<Shader> shader = std::make_shared<Shader>();
		shader->LoadGLSLFormat(vertex.c_str(), fragment.c_str());
		return shader;
	}

	std::shared_ptr<Shader> ShaderLoader::FromGLSLCharPts(const char* const vertex, const char* const fragment)
	{
		std::shared_ptr<Shader> shader = std::make_shared<Shader>();
		shader->LoadGLSLFormat(vertex, fragment);
		return shader;
	}

	std::shared_ptr<Shader> ShaderLoader::FromGLSLString(const std::string& source)
	{
		std::shared_ptr<Shader> shader = std::make_shared<Shader>();
		std::string vertex;
		std::string fragment;
		Shader::ParseShader(source, vertex, fragment);
		shader->LoadGLSLFormat(vertex.c_str(), fragment.c_str());
		return shader;
	}
}
