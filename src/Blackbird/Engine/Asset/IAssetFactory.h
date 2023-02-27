#pragma once

#include "Blackbird/Engine/Asset/VertexArray.h"
#include "Blackbird/Engine/Asset/VertexBuffer.h"

namespace Blackbird
{
	class IAssetFactory
	{
	public:
		virtual Ref<VertexArray> CreateVertexArray() = 0;
		virtual Ref<VertexBuffer> CreateVertexBuffer(float* vertices, uint32_t size) = 0;
		virtual Ref<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t count) = 0;
	};
}
