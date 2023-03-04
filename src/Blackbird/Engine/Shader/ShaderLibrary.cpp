#include "ShaderLibrary.h"

#include "IShaderFactory.h"

namespace Blackbird
{

	bool ShaderLibrary::Exists(const std::string& name)
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		BLACKBIRD_ASSERT(!Exists(name), "Shader {} already exist", name);
		m_Shaders[name] = shader;
	}
	
	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		Add(shader->GetName(), shader);
	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		BLACKBIRD_ASSERT(Exists(name), "Shader {} doesn't exist", name);
		return m_Shaders[name];
	}


	Ref<Shader> ShaderPathsLibrary::LoadFromPath(const std::string& name, const std::string& path)
	{
		Ref<Shader> shader = m_ShaderFactory.CreateFromPath(path);
		Add(name, shader);
		return shader;
	}

	Ref<Shader> ShaderPathsLibrary::LoadFromPath(const std::string& path)
	{
		Ref<Shader> shader = m_ShaderFactory.CreateFromPath(path);
		Add(shader);
		return shader;
	}

}
