#pragma once

#include "Blackbird/Core/Core.h"
#include "RendererAPI.h"
#include "RendererCommand.h"

namespace Blackbird {

	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void Submit(const Ref<VertexArray>& VertexArray);

	};

}