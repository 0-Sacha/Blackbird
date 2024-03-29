#include "OpenGLShader.h"

#include "glad/glad.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{
	static GLenum FromShaderTypeToGLenum(ShaderType type)
	{
		if (type == ShaderType::Vertex) return GL_VERTEX_SHADER;
		if (type == ShaderType::Fragment) return GL_FRAGMENT_SHADER;
		if (type == ShaderType::None) return 0;
	}

	static OpenGLRendererID CompileShader(ShaderType type, const char* const source)
	{
		OpenGLRendererID shaderID = glCreateShader(FromShaderTypeToGLenum(type));

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

			BLKBID_ERROR("{} has not compiled : {:null='Could not retrieve the error message'}", type, log.data());
		}

		return shaderID;
	}

	OpenGLRendererID OpenGLShader::LinkShader(const Shader::Program& program)
	{
		OpenGLRendererID programID = glCreateProgram();
		
		std::vector<OpenGLRendererID> shaders;
		for (auto& [shaderType, shaderData] : program)
		{
			OpenGLRendererID shaderID = CompileShader(shaderType, shaderData.data());
			glAttachShader(programID, shaderID);
			shaders.push_back(shaderID);
		}

		glLinkProgram(programID);

		GLint isLinked = 0;
		glGetProgramiv(programID, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint logLength = 0;
			glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);

			std::vector<GLchar> log(logLength);
			glGetProgramInfoLog(programID, logLength, &logLength, log.data());

			glDeleteProgram(programID);

			for (OpenGLRendererID shader : shaders)
				glDeleteShader(shader);

			BLKBID_ERROR("Program has not link : {:null='Could not retrieve the error message'}", log.data());
		}

		for (OpenGLRendererID shader : shaders)
			glDetachShader(programID, shader);

		return programID;
	}
}
