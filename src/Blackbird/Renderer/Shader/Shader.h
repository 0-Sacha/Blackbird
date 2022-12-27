#pragma once

#include "Blackbird/Core/Core.h"

namespace Blackbird {
	
	enum class ShaderType
	{
		None,
		Vertex,
		Fragment
	};

	class Shader
	{
	public:
		friend class ShaderLoader;

	public:
		virtual ~Shader() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

	public:
		static Ref<Shader> Create(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	};

}

namespace EngineCore::FMT {

	template<typename FormatContext>
	struct FormatType<Blackbird::ShaderType, FormatContext>
	{
		static void Write(const Blackbird::ShaderType t, FormatContext& context) {
			switch (t)
			{
			case Blackbird::ShaderType::None:
				context.PrintCharPt("None Shader");
				break;
			case Blackbird::ShaderType::Vertex:
				context.PrintCharPt("Vertex Shader");
				break;
			case Blackbird::ShaderType::Fragment:
				context.PrintCharPt("Fragment Shader");
				break;
			}
		}
	};
}
