#pragma once

#include "S_Application.h"

namespace Blackbird
{
	class S_Renderer
	{
	public:
		static Renderer& Get()			{ return S_Application::GetRenderer(); }
		static Ref<Renderer>& GetRef()	{ return S_Application::GetRendererRef(); }

	public:
		static void BeginScene(const Camera& camera, const glm::mat4& cameraTransform)	{ Get().BeginScene(camera, cameraTransform); }
		static void EndScene()															{ Get().EndScene(); }

	public:
		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f)) { Get().Submit(shader, vertexArray, transform); }
	};
}
