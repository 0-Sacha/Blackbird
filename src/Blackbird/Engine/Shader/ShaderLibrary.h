#pragma once

#include "Blackbird/Core/Core.h"
#include "Shader.h"

namespace Blackbird
{
	class ShaderLibrary
	{
	public:
		void Add(const Ref<Shader>& shader);
		void Add(const std::string& name, const Ref<Shader>& shader);

		Ref<Shader> LoadFromPath(const std::string& path);
		Ref<Shader> LoadFromPath(const std::string& name, const std::string& path);

		Ref<Shader> Get(const std::string& name);

		bool Exists(const std::string& name);

	public:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}
