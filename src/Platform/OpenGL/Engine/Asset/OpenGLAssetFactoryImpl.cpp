#include "OpenGLAssetFactoryImpl.h"

#include "OpenGLVertexArray.h"
#include "OpenGLBuffer.h"

namespace Blackbird::Platform::OpenGL
{
	Ref<VertexArray> OpenGLAssetFactoryImpl::CreateVertexArray()
	{
		return std::make_shared<OpenGLVertexArray>();
	}

	
	Ref<VertexBuffer> OpenGLAssetFactoryImpl::CreateVertexBuffer(float* vertices, uint32_t size)
	{
		return std::make_shared<OpenGLVertexBuffer>(vertices, size);
	}

	Ref<IndexBuffer> OpenGLAssetFactoryImpl::CreateIndexBuffer(uint32_t* indices, uint32_t count)
	{
		return std::make_shared<OpenGLIndexBuffer>(indices, count);
	}
}
