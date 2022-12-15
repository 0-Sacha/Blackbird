
#include "Spitfirepch.h"
#include "VertexArray.h"

#include "Spitfire/Renderer/Renderer.h"

#include "Platform/OpenGL/Renderer/Asset/OpenGLVertexArray.h"

namespace Spitfire {


	VertexArray* VertexArray::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	SPITFIRE_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return new OpenGLVertexArray();
		}

		SPITFIRE_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

}