#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_Renderer
	{
	public:
		static void BeginScene(OrthographicCamera& camera) { StaticContext::GetRenderer().BeginScene(camera); }
		static void EndScene() { StaticContext::GetRenderer().EndScene(); }

	public:
		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f)) { StaticContext::GetRenderer().Submit(shader, vertexArray, transform); }
	};
}
