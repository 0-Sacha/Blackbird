#pragma once

#include "Blackbird/Engine/Asset/IAssetFactory.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	class OpenGLAssetFactory final : public IAssetFactory
	{
	public:
		~OpenGLAssetFactory() override = default;

	public:
		Ref<VertexArray> CreateVertexArray() override;
		
		Ref<VertexBuffer> CreateVertexBuffer(uint32_t size) override;
		Ref<VertexBuffer> CreateVertexBuffer(float* vertices, uint32_t size) override;

		Ref<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t count) override;
	};
}
