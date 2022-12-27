
#include "Blackbirdpch.h"
#include "Texture.h"

#include "Blackbird/Renderer/Renderer.h"

#include "Platform/OpenGL/Renderer/OpenGLTexture/OpenGLTexture.h"

namespace Blackbird {

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:	BLACKBIRD_ASSERT(false, "RendererAPI:None is not supported yet!"); return nullptr;
		case RendererAPI::API::OpenGL:	return std::make_shared<Platform::OpenGL::OpenGLTexture2D>(path);
		}

		BLACKBIRD_ASSERT(false, "There is no Renderer API set!");
		return nullptr;
	}

}