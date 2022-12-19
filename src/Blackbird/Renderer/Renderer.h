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
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static inline SceneData* m_SceneData = new SceneData;
	};

}