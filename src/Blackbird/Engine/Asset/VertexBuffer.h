
#pragma once

#include "Blackbird/Core/Core.h"
#include "VertexBufferLayout.h"

namespace Blackbird {

	/////---------- VertexBuffer ----------/////

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Release() const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const = 0;

		virtual void SetData(const void* data, std::uint32_t size) = 0;
	};



	/////---------- IndexBuffer ----------/////

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Release() const = 0;

		virtual uint32_t GetCount() = 0;
	};
}
