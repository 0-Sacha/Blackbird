
#include "Blackbirdpch.h"
#include "RendererCommand.h"

#include "Platform/OpenGL/Renderer/OpenGLRendererAPI.h"

namespace Blackbird {

	RendererAPI* RendererCommand::s_RendererAPI = new OpenGLRendererAPI();

}