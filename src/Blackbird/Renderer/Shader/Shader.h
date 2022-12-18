#pragma once

#include "Blackbird/Core/Core.h"
#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace Blackbird {
	
	class ShaderLoader;

	enum class ShaderType : GLenum
	{
		None,
		Vertex = GL_VERTEX_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	class Shader
	{
	public:
		friend class ShaderLoader;

	public:
		Shader() = default;
		~Shader();

	public:
		RendererID GetRendererID() { return m_RendererID; }

	public:
		void Bind() const;
		void Unbind() const;

		void UploadUniformMat4(const std::string& name, const glm::mat4& mat);

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





