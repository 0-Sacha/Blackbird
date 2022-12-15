#pragma once

#include "Spitfire/Core/Core.h"
#include "RendererAPI.h"
#include "RendererCommand.h"

namespace Spitfire {

	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const Ref<VertexArray>& VertexArray);

	};

}