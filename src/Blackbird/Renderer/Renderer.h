#pragma once

#include "Blackbird/Core/Core.h"
#include "RendererAPI.h"
#include "RendererCommand.h"
#include "Camera/OrthographicCamera.h"
#include "Shader/Shader.h"

namespace Blackbird {

	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

	public:
		static void OnWindowResize(std::uint32_t width, std::uint32_t height);

	public:
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static inline SceneData* m_SceneData = new SceneData;
	};

}