#pragma once

#include "Blackbird/Engine/Asset/VertexArray.h"
#include "Blackbird/Engine/Asset/VertexBuffer.h"

#include "Blackbird/PlatformAPI.h"

namespace Blackbird
{
	class AssetFactory
	{
	public:
		static Ref<VertexArray> CreateVertexArray()										{ return PlatformAPI::GetInstance().GetAssetFactory().CreateVertexArray(); }
		static Ref<VertexBuffer> CreateVertexBuffer(float* vertices, uint32_t size)		{ return PlatformAPI::GetInstance().GetAssetFactory().CreateVertexBuffer(vertices, size); }
		static Ref<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t count)	{ return PlatformAPI::GetInstance().GetAssetFactory().CreateIndexBuffer(indices, count); }
	};
}
