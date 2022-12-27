
#include "Blackbirdpch.h"

#include "VertexBuffer.h"
#include "Blackbird/Renderer/Renderer.h"

#include "Platform/OpenGL/Renderer/Asset/OpenGLBuffer.h"

namespace Blackbird {

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch(RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	BLACKBIRD_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return std::make_shared<Platform::OpenGL::OpenGLVertexBuffer>(vertices, size);
		}

		BLACKBIRD_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	BLACKBIRD_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return std::make_shared<Platform::OpenGL::OpenGLIndexBuffer>(indices, count);
		}

		BLACKBIRD_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

}