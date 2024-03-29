#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Shader/ShaderData.h"

namespace Blackbird
{
	struct BufferElements
	{
	public:
		ShaderData::Type ShaderDataType;
		std::string Name;
		uint32_t Offset;
		uint32_t Size;
		bool Normalized;

	public:
		BufferElements() = default;

		BufferElements(ShaderData::Type type, const std::string& name, bool normalized = false)
			: ShaderDataType(type), Name(name), Size(ShaderData::GetSizeOf(type)), Offset(0), Normalized(normalized)
		{ }

		BufferElements(ShaderData::Type type, std::string&& name, bool normalized = false)
			: ShaderDataType(type), Name(std::move(name)), Size(ShaderData::GetSizeOf(type)), Offset(0), Normalized(normalized)
		{ }

	public:
		inline uint32_t GetComponentCount() const { return ShaderData::GetComponentCountOf(ShaderDataType); }
	};


	/////---------- BufferLayout ----------/////

	class BufferLayout
	{
	public:
		BufferLayout() = default;
		BufferLayout(const std::initializer_list<BufferElements>& elements);

	public:
		inline const std::vector<BufferElements>& GetElements()			{ return m_Elements; }
		inline const std::vector<BufferElements>& GetElements() const	{ return m_Elements; }
		inline uint32_t GetStride() const { return m_Stride; }

		template <typename... Args>
		BufferElements& Emplace(Args&&... args) { return m_Elements.emplace_back(std::forward<Args>(args)...); }
		void Push(const BufferElements& element) { return m_Elements.push_back(element); }

	private:
		void CalculateOffsetAndStride();

	private:
		std::vector<BufferElements> m_Elements;
		uint32_t m_Stride;
	};

}
