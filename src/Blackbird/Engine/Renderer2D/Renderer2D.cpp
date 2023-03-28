#include "Renderer2D.h"

#include "Renderer2DStorage.h"
#include "Blackbird/Engine/IRendererCommand.h"

namespace Blackbird
{
	void Renderer2D::Init(Ref<EngineAPI>& engineAPI)
	{
		m_EngineAPI = engineAPI;
		m_Storage = std::make_unique<Renderer2DStorage>(*this);
		m_Storage->Init();
	}

	void Renderer2D::Shutdown()
	{
		m_Storage->Shutdown();
	}

	void Renderer2D::BeginScene(const Camera& camera, const glm::mat4& cameraTransform)
	{
		glm::mat4 viewProjectionMatrix = camera.GetProjection() * glm::inverse(cameraTransform);
		
		m_Storage->QuadManager.BeginScene(viewProjectionMatrix);
	}

	void Renderer2D::EndScene()
	{
		m_Storage->QuadManager.EndScene();
	}

	Renderer2DStatistics Renderer2D::GetStats()
	{
		Renderer2DStatistics res;
		res.DrawCall = 0;

		res.QuadStats = m_Storage->QuadManager.Stats;
		res.DrawCall += m_Storage->QuadManager.Stats.DrawCall;

		return res;
	}

	void Renderer2D::ResetStats()
	{
		m_Storage->QuadManager.Stats.Reset();
	}

}
