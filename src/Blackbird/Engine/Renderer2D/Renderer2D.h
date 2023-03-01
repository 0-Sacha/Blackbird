#pragma once

#include "Blackbird/Engine/Camera/OrthographicCamera.h"
#include "Blackbird/Engine/Texture/Texture.h"

#include "Blackbird/EngineAPI.h"

#include "Renderer2DStorage.h"

namespace Blackbird
{
	class IDesigner2D;

	class Renderer2D
	{
	public:
		void Init(Ref<EngineAPI>& engineAPI);
		void Shutdown();

	public:
		void BeginScene(const OrthographicCamera& camera);
		void EndScene();

	public:
		void Draw(IDesigner2D& designer);

	public:
		QuadDesigner CreateQuadDesigner() { return QuadDesigner(this); }

	public:
		EngineAPI& Engine() { return *m_EngineAPI; }
		Ref<EngineAPI> RefEngine() { return m_EngineAPI; }
		Renderer2DStorage& Storage() { return *m_Storage; }

	private:
		Ref<EngineAPI> m_EngineAPI;
		Scope<Renderer2DStorage> m_Storage = nullptr;
	};
}
