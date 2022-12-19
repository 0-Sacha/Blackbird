
#include "Blackbirdpch.h"
#include "VertexArray.h"

#include "Blackbird/Renderer/Renderer.h"

#include "Platform/OpenGL/Renderer/Asset/OpenGLVertexArray.h"

namespace Blackbird {


	VertexArray* VertexArray::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	BLACKBIRD_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return new OpenGLVertexArray();
		}

		BLACKBIRD_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

}