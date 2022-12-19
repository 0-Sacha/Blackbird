
#include "Blackbirdpch.h"

#include "Blackbird/Core/Core.h"

#include "Shader.h"

namespace Blackbird {


	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::UploadUniformMat4(const std::string& name, const glm::mat4& mat)
	{
		GLint location = glGetUniformLocation(m_RendererID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::LoadGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
	{
		std::string vertex;
		Shader::ReadFileInString(vertexShaderPath, vertex);
		std::string fragment;
		Shader::ReadFileInString(fragmentShaderPath, fragment);
		LoadGLSLFormat(vertex.c_str(), fragment.c_str());
	}

	void Shader::LoadGLSLTextFile(const std::string& path)
	{
		std::string source;
		Shader::ReadFileInString(path, source);
		std::string vertex;
		std::string fragment;
		Shader::ParseShader(source, vertex, fragment);
		LoadGLSLFormat(vertex.c_str(), fragment.c_str());
	}


	void Shader::LoadGLSLFormat(const char* const vertex, const char* const fragment)
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

	RendererID Shader::CompileShader(ShaderType type, const char* const source)
	{
		RendererID shaderID = glCreateShader((GLenum)type);

		glShaderSource(shaderID, 1, &source, nullptr);

		glCompileShader(shaderID);
		
		GLint isCompiled = 0;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isCompiled);
		if(isCompiled == GL_FALSE)
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

	void Shader::ReadFileInString(const std::string& path, std::string& str)
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

	void Shader::ParseShader(const std::string& str, std::string& vertex, std::string& fragment)
	{
		std::string line;
		std::stringstream source(str);
		std::stringstream strstream[2];

		ShaderType type = ShaderType::None;
		while (getline(source, line)) {
			if (line.find("#shader") != std::string::npos) {
				if (line.find("vertex") != std::string::npos)
					type = ShaderType::Vertex;
				else if (line.find("fragment") != std::string::npos)
					type = ShaderType::Fragment;
			}
			else if (type != ShaderType::None) {
				strstream[(int)type] << line << "\n";
			}
		}
		
	}

}