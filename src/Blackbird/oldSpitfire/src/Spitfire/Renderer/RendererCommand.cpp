
#include "Spitfirepch.h"
#include "RendererCommand.h"

#include "Platform/OpenGL/Renderer/OpenGLRendererAPI.h"

namespace Spitfire {

	RendererAPI* RendererCommand::s_RendererAPI = new OpenGLRendererAPI();

}