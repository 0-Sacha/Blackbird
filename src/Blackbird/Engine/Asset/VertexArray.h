#pragma once

#include "Blackbird/Core/Core.h"
#include "VertexBuffer.h"

namespace Blackbird
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

	public:
		virtual void Bind() const = 0;
		virtual void Release() const = 0;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;

		virtual const std::vector<Ref<VertexBuffer>> GetVertexBuffers() const = 0;
		virtual const Ref<IndexBuffer> GetIndexBuffer() const = 0;
	};
}
