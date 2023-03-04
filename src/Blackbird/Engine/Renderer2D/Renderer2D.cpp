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

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		m_Storage->QuadManager.BeginScene(camera);
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
