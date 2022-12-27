#pragma once

#include "Platform/OpenGL/OpenGLCore.h"
#include "Blackbird/Renderer/Shader/Shader.h"

namespace Blackbird::Platform::OpenGL 
{

	class OpenGLShader : public Shader
	{
	public:
		friend class ShaderLoader;

	public:
		OpenGLShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		~OpenGLShader() override;

	public:
		void Bind() const override;
		void Unbind() const override;

	public:
		RendererID GetRendererID() { return m_RendererID; }

	public:
		void UploadUniformInt(const std::string& name, int data);

		void UploadUniformFloat(const std::string& name, float data);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& data);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& data);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& data);
		
		void UploadUniformMat3(const std::string& name, const glm::mat3& mat);
		void UploadUniformMat4(const std::string& name, const glm::mat4& mat);

	private:
		RendererID CompileShader(ShaderType type, const char* const source);
		void LoadGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		void LoadGLSLFormat(const char* const vertex, const char* const fragment);


	private:
		RendererID m_RendererID;
	};

}
