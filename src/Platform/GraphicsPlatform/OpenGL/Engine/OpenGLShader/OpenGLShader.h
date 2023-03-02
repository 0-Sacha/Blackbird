#pragma once

#include "Platform/GraphicsPlatform/OpenGL/OpenGLCore.h"

#include "Blackbird/Engine/Shader/Shader.h"

namespace Blackbird::GraphicsPlatform::OpenGL 
{

	class OpenGLShader : public Shader
	{
	public:
		~OpenGLShader() override;

		OpenGLShader(const std::string& name, RendererID id)
			: m_Name(name)
			, m_RendererID(id)
		{}

	public:
		void Bind() const override;
		void Release() const override;

		const std::string& GetName() const override { return m_Name; }

	public:
		RendererID GetRendererID() { return m_RendererID; }

	public:
		void SetInt(const std::string& name, int data) override									{ UploadUniformInt(name, data); }
		void SetIntArray(const std::string& name, int* data, std::uint32_t count) override		{ UploadUniformIntArray(name, data, count); }
		void SetFloat(const std::string& name, float data) override								{ UploadUniformFloat(name, data); }
		void SetFloat2(const std::string& name, const glm::vec2& data) override					{ UploadUniformFloat2(name, data); }
		void SetFloat3(const std::string& name, const glm::vec3& data) override					{ UploadUniformFloat3(name, data); }
		void SetFloat4(const std::string& name, const glm::vec4& data) override					{ UploadUniformFloat4(name, data); }
		void SetFloatArray(const std::string& name, float* data, std::uint32_t count) override	{ UploadUniformFloatArray(name, data, count); }
		void SetMat3(const std::string& name, const glm::mat3& data) override					{ UploadUniformMat3(name, data); }
		void SetMat4(const std::string& name, const glm::mat4& data) override					{ UploadUniformMat4(name, data); }

		void UploadUniformInt(const std::string& name, int data);
		void UploadUniformIntArray(const std::string& name, int* data, std::uint32_t count);
		void UploadUniformFloat(const std::string& name, float data);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& data);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& data);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& data);
		void UploadUniformFloatArray(const std::string& name, float* data, std::uint32_t count);
		void UploadUniformMat3(const std::string& name, const glm::mat3& data);
		void UploadUniformMat4(const std::string& name, const glm::mat4& data);

	public:
		static RendererID LinkShader(const Shader::Program& program);

	private:
		std::string m_Name;
		RendererID m_RendererID;
	};

}
