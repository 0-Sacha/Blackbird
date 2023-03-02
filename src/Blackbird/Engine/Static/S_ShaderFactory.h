#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_ShaderFactory
	{
	public:
		static Ref<Shader> CreateFromPath(const std::string& path) 							{ return StaticContext::Engine().ShaderFactory().CreateFromPath(path); }
		static Ref<Shader> CreateFromPaths(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath) { return StaticContext::Engine().ShaderFactory().CreateFromPaths(name, vertexPath, fragmentPath); }
		static Ref<Shader> CreateFromSrcs(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc) 	{ return StaticContext::Engine().ShaderFactory().CreateFromSrcs(name, vertexSrc, fragmentSrc); }
	};
}
