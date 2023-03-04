#pragma once

#include "S_Application.h"

namespace Blackbird
{
	class S_ShaderFactory
	{
	public:
		static IShaderFactory& Get() { return S_Application::Engine().ShaderFactory(); }

	public:
		static Ref<ShaderPathsLibrary> CreateShaderPathsLibrary() { return Get().CreateShaderPathsLibrary(); }

	public:
		static Ref<Shader> CreateFromPath(const std::string& path) 																	{ return Get().CreateFromPath(path); }
		static Ref<Shader> CreateFromPaths(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath) { return Get().CreateFromPaths(name, vertexPath, fragmentPath); }
		static Ref<Shader> CreateFromSrcs(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc) 	{ return Get().CreateFromSrcs(name, vertexSrc, fragmentSrc); }
	};
}
