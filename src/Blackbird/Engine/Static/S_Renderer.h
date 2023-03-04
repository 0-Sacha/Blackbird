#pragma once

#include "S_Application.h"

namespace Blackbird
{
	class S_Renderer
	{
	public:
		static Renderer& Get() { return S_Application::GetRenderer(); }

	public:
		static void BeginScene(OrthographicCamera& camera)	{ Get().BeginScene(camera); }
		static void EndScene()								{ Get().EndScene(); }

	public:
		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f)) { Get().Submit(shader, vertexArray, transform); }
	};
}
