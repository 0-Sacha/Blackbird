#pragma once

#include "Blackbird/Core/Core.h"

#include "glm/glm.hpp"

#include <unordered_map>
#include <string>

namespace Blackbird
{
	enum class ShaderType
	{
		None,
		Vertex,
		Fragment
	};

	class Shader
	{
	public:
		using Program = std::unordered_map<ShaderType, std::string>;

	public:
		virtual ~Shader() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Release() const = 0;

		virtual const std::string& GetName() const = 0;

	public:
		virtual void SetInt(const std::string& name, int data) = 0;
		virtual void SetIntArray(const std::string& name, int* data, std::uint32_t count) = 0;
		virtual void SetFloat(const std::string& name, float data) = 0;
		virtual void SetFloat2(const std::string& name, const glm::vec2& data) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& data) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& data) = 0;
		virtual void SetFloatArray(const std::string& name, float* data, std::uint32_t count) = 0;
		virtual void SetMat3(const std::string& name, const glm::mat3& data) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& data) = 0;

	public:
		static Ref<Shader> Create(const std::string& name, const Program& program);
	};

}

namespace ProjectCore::FMT
{
	template<typename FormatContext>
	struct FormatterType<Blackbird::ShaderType, FormatContext>
	{
		static void Format(const Blackbird::ShaderType t, FormatContext& context) {
			switch (t)
			{
			case Blackbird::ShaderType::None:
				context.BufferOut().WriteCharArray("None Shader");
				break;
			case Blackbird::ShaderType::Vertex:
				context.BufferOut().WriteCharArray("Vertex Shader");
				break;
			case Blackbird::ShaderType::Fragment:
				context.BufferOut().WriteCharArray("Fragment Shader");
				break;
			}
		}
	};
}
