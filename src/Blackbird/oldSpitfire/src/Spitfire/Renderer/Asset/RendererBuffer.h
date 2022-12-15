
#pragma once

#include "Spitfire/Core/Core.h"
#include "RendererBufferLayout.h"

namespace Spitfire {

	/////---------- VertexBuffer ----------/////

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;


	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const = 0;

	public:
		static VertexBuffer* Create(float* vertices, uint32_t size);
	};



	/////---------- IndexBuffer ----------/////

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() = 0;

	public:
		static IndexBuffer* Create(uint32_t* indices, uint32_t count);
	};

}