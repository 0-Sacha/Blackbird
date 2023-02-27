#include "OpenGLShader.h"

#include "glm/gtc/type_ptr.hpp"

#include <glad/glad.h>

namespace Blackbird::GraphicsPlatform::OpenGL
{
	void OpenGLShader::UploadUniformInt(const std::string& name, int data)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform1i(location, data);
	}

	void OpenGLShader::UploadUniformFloat(const std::string& name, float data)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform1f(location, data);
	}

	void OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2& data)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform2f(location, data.x, data.y);
	}

	void OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3& data)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform3f(location, data.x, data.y, data.z);
	}

	void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4& data)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniform4f(location, data.x, data.y, data.z, data.w);
	}
	
	void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& data)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(data));
	}

	void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& data)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(data));
	}
}
