#include "OpenGLAssetFactory.h"

#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	Ref<VertexArray> OpenGLAssetFactory::CreateVertexArray()
	{
		return std::make_shared<OpenGLVertexArray>();
	}

	
	Ref<VertexBuffer> OpenGLAssetFactory::CreateVertexBuffer(float* vertices, uint32_t size)
	{
		return std::make_shared<OpenGLVertexBuffer>(vertices, size);
	}

	Blackbird::Ref<Blackbird::VertexBuffer> OpenGLAssetFactory::CreateVertexBuffer(uint32_t size)
	{
		return std::make_shared<OpenGLVertexBuffer>(size);
	}

	Ref<IndexBuffer> OpenGLAssetFactory::CreateIndexBuffer(uint32_t* indices, uint32_t count)
	{
		return std::make_shared<OpenGLIndexBuffer>(indices, count);
	}
}
