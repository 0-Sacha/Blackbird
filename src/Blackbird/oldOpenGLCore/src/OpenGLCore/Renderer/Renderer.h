#pragma once

#include "OpenGLCore/Core/Core.h"

namespace OGLC {

	enum class RendererAPI
	{
		None,
		OpenGL
	};

	class Renderer
	{
	public:
		static inline RendererAPI GetRendererAPI() { return s_RendererAPI; };

	private:
		static RendererAPI s_RendererAPI;
	};

}