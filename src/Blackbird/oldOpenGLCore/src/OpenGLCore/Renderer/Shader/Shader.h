#pragma once

#include <glad/glad.h>

namespace OGLC {
	
	enum class ShaderType : GLenum
	{
		None,
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	class Shader
	{
	public:
		~Shader();

	public:
		RendererID GetRendererID() { return m_RendererID; }

	public:
		static Shader* FromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		static Shader* FromGLSLTextFile(const std::string& path);

		static Shader* FromGLSLStrings(const std::string& vertex, const std::string& fragment);
		static Shader* FromGLSLCharPts(const char* const vertex, const char* const fragment);
		static Shader* FromGLSLString(const std::string& source);

	private:
		Shader() = default;

		RendererID CompileShader(ShaderType type, const char* const source);
		static void ReadFileInString(const std::string& path, std::string& str);
		static void ParseShader(const std::string& str, std::string& vertex, std::string& fragment);

	private:
		void LoadGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		void LoadGLSLTextFile(const std::string& path);

		void LoadGLSLFormat(const char* const vertex, const char* const fragment);

	private:
		RendererID m_RendererID;
	};

}

namespace CPPTools::Fmt {

	template<>
	struct FormatType<OGLC::ShaderType>
	{
		static void Write(const OGLC::ShaderType t, Formater& formater, const FormatData& data) {
			switch (t)
			{
			case OGLC::ShaderType::None:
				formater.WriteCharPt("None Shader");
				break;
			case OGLC::ShaderType::Vertex:
				formater.WriteCharPt("Vertex Shader");
				break;
			case OGLC::ShaderType::Fragment:
				formater.WriteCharPt("Fragment Shader");
				break;
			}
		}
	};
}





