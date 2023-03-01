#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_AssetFactory
	{
	public:
		static Ref<VertexArray> CreateVertexArray()										{ return StaticContext::Engine().AssetFactory().CreateVertexArray(); }
		static Ref<VertexBuffer> CreateVertexBuffer(float* vertices, uint32_t size)		{ return StaticContext::Engine().AssetFactory().CreateVertexBuffer(vertices, size); }
		static Ref<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t count)	{ return StaticContext::Engine().AssetFactory().CreateIndexBuffer(indices, count); }
	};
}
