#pragma once

#include <glad/glad.h>

namespace Blackbird {
	
	enum class ShaderType : GLenum
	{
		None,
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	class Shader
	{
	public:
		Shader() = default;
		~Shader();

	public:
		RendererID GetRendererID() { return m_RendererID; }

	public:
		void Bind() const;
		void Unbind() const;


	public:
		static Shader* FromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		static Shader* FromGLSLTextFile(const std::string& path);

		static Shader* FromGLSLStrings(const std::string& vertex, const std::string& fragment);
		static Shader* FromGLSLCharPts(const char* const vertex, const char* const fragment);
		static Shader* FromGLSLString(const std::string& source);


	private:
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





