
#include "Spitfirepch.h"

#include "RendererBuffer.h"
#include "Spitfire/Renderer/Renderer.h"

#include "Platform/OpenGL/Renderer/Asset/OpenGLBuffer.h"

namespace Spitfire {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch(RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	SPITFIRE_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
		}

		SPITFIRE_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	SPITFIRE_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return new OpenGLIndexBuffer(indices, count);
		}

		SPITFIRE_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

}