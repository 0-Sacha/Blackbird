
#include "Shader.h"
#include "IShaderFactory.h"

namespace Blackbird
{
	static void ReadFileInString(const std::string& path, std::string& str)
	{
		std::ifstream ifile(path, std::ios::in | std::ios::binary);
		if (!ifile)
		{
			BLACKBIRD_ERROR("Could not open file : {}", path);
			return;
		}

		ifile.seekg(0, std::ios::end);
		str.resize((size_t)ifile.tellg());
		ifile.seekg(0, std::ios::beg);
		ifile.read(str.data(), str.size());
		ifile.close();
	}

	ShaderType FromTokenToShaderType(const std::string& token)
	{
		if (token == "fragment" || token == "pixel")
			return ShaderType::Fragment;
		if (token == "vertex")
			return ShaderType::Vertex;
		BLACKBIRD_ASSERT(false, "Invalid Sharder type in token #type {}", token);
		return ShaderType::None;
	}

	static std::unordered_map<ShaderType, std::string> PreProcess(std::string& data)
	{
		std::unordered_map<ShaderType, std::string> program;

		std::string_view token = "#type";
		size_t pos = data.find(token.data(), 0);
		while (pos != std::string::npos)
		{
			size_t eol = data.find_first_of("\r\n", pos);
			if (eol == std::string::npos)
			{
				BLACKBIRD_ASSERT(false, "Shader Syntax error");
			}

			size_t beg = pos + token.size() + 1;
			std::string type = data.substr(beg, eol - beg);
			size_t nextLinePos = data.find_first_not_of("\r\n", eol);
			pos = data.find(token.data(), nextLinePos);
			size_t offset = nextLinePos;
			if (nextLinePos == std::string::npos)
				offset = data.size() - 1;
			std::string shader = data.substr(nextLinePos, pos - offset);
			program[FromTokenToShaderType(type)] = shader;
		}

		return program;
	}

	Ref<Shader> IShaderFactory::CreateFromPath(const std::string& path)
	{
		std::string data;
		ReadFileInString(path, data);
		std::unordered_map<ShaderType, std::string> program = PreProcess(data);


		auto lastSlash = path.find_last_of("/\\");
		lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
		auto lastDot = path.rfind('.');
		auto count = lastDot == std::string::npos ? path.size() : lastDot;
		count -= lastSlash;
		std::string name = path.substr(lastSlash, count);
		return Create(name, program);
	}

	Ref<Shader> IShaderFactory::CreateFromPaths(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
	{
		std::unordered_map<ShaderType, std::string> program;

		std::string vertex;
		ReadFileInString(vertexPath, vertex);
		program[ShaderType::Vertex] = vertex;

		std::string fragment;
		ReadFileInString(fragmentPath, fragment);
		program[ShaderType::Fragment] = fragment;

		return Create(name, program);
	}

	Ref<Shader> IShaderFactory::CreateFromSrcs(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		std::unordered_map<ShaderType, std::string> program;
		program[ShaderType::Vertex] = vertexSrc;
		program[ShaderType::Fragment] = fragmentSrc;
		return Create(name, program);
	}
}
