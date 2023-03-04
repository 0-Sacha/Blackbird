#pragma once

#include "Blackbird/Core/Core.h"
#include "Shader.h"

namespace Blackbird
{
	class IShaderFactory;

	class ShaderLibrary
	{
	public:
		bool Exists(const std::string& name);
		void Add(const Ref<Shader>& shader);
		void Add(const std::string& name, const Ref<Shader>& shader);
		Ref<Shader> Get(const std::string& name);

	protected:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};

	class ShaderPathsLibrary : public ShaderLibrary
	{
	public:
		ShaderPathsLibrary(IShaderFactory& factory)
			: m_ShaderFactory(factory)
		{}

	public:
		Ref<Shader> LoadFromPath(const std::string& path);
		Ref<Shader> LoadFromPath(const std::string& name, const std::string& path);

	protected:
		using ShaderLibrary::Add;

	protected:
		IShaderFactory& m_ShaderFactory;
	};

}
