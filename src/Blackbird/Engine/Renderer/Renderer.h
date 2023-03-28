#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Camera/Camera.h"
#include "Blackbird/Engine/Shader/Shader.h"

#include "Blackbird/EngineAPI.h"

namespace Blackbird
{
	class Renderer
	{
	public:
		void Init(Ref<EngineAPI>& engineAPI);
		void Shutdown();

	public:
		void BeginScene(const Camera& camera, const glm::mat4& cameraTransform);
		void EndScene();

		void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

	private:
		Ref<EngineAPI> m_EngineAPI;
		Scope<SceneData> m_SceneData;
	};
}
