#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_AssetFactory
	{
	public:
		static IAssetFactory& Get() { return StaticContext::Engine().AssetFactory(); }

	public:
		static Ref<VertexArray> CreateVertexArray()										{ return Get().CreateVertexArray(); }
		static Ref<VertexBuffer> CreateVertexBuffer(float* vertices, uint32_t size)		{ return Get().CreateVertexBuffer(vertices, size); }
		static Ref<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t count)	{ return Get().CreateIndexBuffer(indices, count); }
	};
}
