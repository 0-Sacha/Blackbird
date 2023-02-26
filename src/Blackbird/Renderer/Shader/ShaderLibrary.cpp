
#include "Blackbirdpch.h"
#include "ShaderLibrary.h"
#include "ShaderFactory.h"

namespace Blackbird
{

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		BLACKBIRD_ASSERT(!Exists(name), "Shader {} already exist", name);
		m_Shaders[name] = shader;
	}
	
	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		Add(shader->GetName(), shader);
	}

	Ref<Shader> ShaderLibrary::LoadFromPath(const std::string& name, const std::string& path)
	{
		 Ref<Shader> shader = ShaderFactory::CreateFromPath(path);
		 Add(name, shader);
		 return shader;
	}

	Ref<Shader> ShaderLibrary::LoadFromPath(const std::string& path)
	{
		Ref<Shader> shader = ShaderFactory::CreateFromPath(path);
		Add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		BLACKBIRD_ASSERT(Exists(name), "Shader {} already exist", name);
		return m_Shaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name)
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}

}
