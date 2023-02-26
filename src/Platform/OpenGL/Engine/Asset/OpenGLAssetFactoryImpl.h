#pragma once

#include "Blackbird/Engine/Asset/AssetFactoryImpl.h"

namespace Blackbird::Platform::OpenGL
{
	class OpenGLAssetFactoryImpl final : public AssetFactoryImpl
	{
	public:
		Ref<VertexArray> CreateVertexArray() override;

		Ref<VertexBuffer> CreateVertexBuffer(float* vertices, uint32_t size) override;
		Ref<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t count) override;
	};
}
