
#include "Blackbirdpch.h"

#include "VertexBuffer.h"
#include "Blackbird/Renderer/Renderer.h"

#include "Platform/OpenGL/Renderer/Asset/OpenGLBuffer.h"

namespace Blackbird {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch(RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	BlACKBIRD_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
		}

		BlACKBIRD_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	BlACKBIRD_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return new OpenGLIndexBuffer(indices, count);
		}

		BlACKBIRD_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

}