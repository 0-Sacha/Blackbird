

#include "Renderer.h"
#include "Blackbird/Engine/Renderer2D/Renderer2D.h"

namespace Blackbird
{
	void Renderer::Init(Ref<EngineAPI>& engineAPI)
	{
		m_EngineAPI = engineAPI;
		m_SceneData = std::make_unique<SceneData>();
	}

	void Renderer::Shutdown()
	{
		m_SceneData = nullptr;
	}

	void Renderer::BeginScene(const Camera& camera, const glm::mat4& cameraTransform)
	{
		glm::mat4 viewProjectionMatrix = camera.GetProjection() * glm::inverse(cameraTransform);

		m_SceneData->ViewProjectionMatrix = viewProjectionMatrix;
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
		shader->SetMat4("u_Transform", transform);

		vertexArray->Bind();
		m_EngineAPI->RendererCommand().DrawIndexed(vertexArray);
	}
}
