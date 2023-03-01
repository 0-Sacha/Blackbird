#include "Renderer2D.h"

#include "Renderer2DStorage.h"
#include "Blackbird/Engine/IRendererCommand.h"

namespace Blackbird
{
	void Renderer2D::Init(Ref<EngineAPI>& engineAPI)
	{
		m_EngineAPI = engineAPI;

		m_Storage = CreateScope<Renderer2DStorage>();
		m_Storage->Init(*this);
	}

	void Renderer2D::Shutdown()
	{
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		m_Storage->QuadManager.BeginScene(camera);
	}

	void Renderer2D::EndScene()
	{

	}
}
