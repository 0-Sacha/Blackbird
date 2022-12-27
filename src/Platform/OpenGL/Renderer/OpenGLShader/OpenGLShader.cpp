
#include "Blackbirdpch.h"

#include "OpenGLShader.h"
#include <glad/glad.h>

namespace Blackbird::Platform::OpenGL
{

	OpenGLShader::OpenGLShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
	{
		LoadGLSLTextFiles(vertexShaderPath, fragmentShaderPath);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

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

	void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& mat)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	}

	void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& mat)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	}


	// COMPILE
	void OpenGLShader::LoadGLSLFormat(const char* const vertex, const char* const fragment)
	{
		RendererID programID = glCreateProgram();
		int glShaderIdx = 0;

		RendererID vertexID = CompileShader(ShaderType::Vertex, vertex);
		glAttachShader(programID, vertexID);
		RendererID fragmentID = CompileShader(ShaderType::Fragment, fragment);
		glAttachShader(programID, fragmentID);

		glLinkProgram(programID);

		GLint isLinked = 0;
		glGetProgramiv(programID, GL_LINK_STATUS, &isLinked);
		if(isLinked == GL_FALSE)
		{
			GLint logLength = 0;
			glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);

			std::vector<GLchar> log(logLength);
			glGetProgramInfoLog(programID, logLength, &logLength, log.data());

			glDeleteProgram(programID);
			programID = 0;

			BLACKBIRD_ERROR("Program has not link : {}", log.data());
		}

		m_RendererID = programID;
	}

	static void ReadFileInString(const std::string& path, std::string& str)
	{
		std::ifstream ifile(path, std::ios::in | std::ios::binary);
		if(ifile)
		{
			// get file size
			ifile.seekg(0, std::ios::end); // set pos
			str.resize((size_t)ifile.tellg()); // get pos

			ifile.seekg(0, std::ios::beg);
			ifile.read(&str[0], str.size()); // read in str
			ifile.close();
		} else {
			BLACKBIRD_ERROR("Could not open file : {}", path);
		}
	}

	void OpenGLShader::LoadGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
	{
		std::string vertex;
		ReadFileInString(vertexShaderPath, vertex);
		std::string fragment;
		ReadFileInString(fragmentShaderPath, fragment);
		LoadGLSLFormat(vertex.c_str(), fragment.c_str());
	}

	static GLenum FromShaderTypeToGLenum(ShaderType type)
	{
		if (type == ShaderType::Vertex) return GL_VERTEX_SHADER;
		if (type == ShaderType::Fragment) return GL_FRAGMENT_SHADER;
		if (type == ShaderType::None) return 0;
	}

	RendererID OpenGLShader::CompileShader(ShaderType type, const char* const source)
	{
		RendererID shaderID = glCreateShader(FromShaderTypeToGLenum(type));

		glShaderSource(shaderID, 1, &source, nullptr);

		glCompileShader(shaderID);

		GLint isCompiled = 0;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint logLenght = 0;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLenght);

			std::vector<GLchar> log(logLenght);
			glGetShaderInfoLog(shaderID, logLenght, &logLenght, log.data());

			glDeleteShader(shaderID);
			shaderID = 0;

			BLACKBIRD_ERROR("{} has not compiled : {}", type, log.data());
		}

		return shaderID;
	}
}
