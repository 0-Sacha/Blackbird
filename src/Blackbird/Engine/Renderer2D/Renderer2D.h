#pragma once

#include "Blackbird/Engine/Camera/Camera.h"
#include "Blackbird/Engine/Texture/Texture.h"

#include "Blackbird/EngineAPI.h"

#include "Renderer2DStorage.h"
#include "Statistics2D.h"

namespace Blackbird
{
	struct Renderer2DStatistics
	{
		std::uint32_t DrawCall;
		QuadStatistics QuadStats;
	};

	class Renderer2D
	{
	public:
		void Init(Ref<EngineAPI>& engineAPI);
		void Shutdown();

	public:
		void BeginScene(const Camera& camera, const glm::mat4& cameraTransform);
		void EndScene();

	public:
		Renderer2DStatistics GetStats();
		void ResetStats();

	public:
		TransformQuadDesigner CreateQuadDesignerT() { return TransformQuadDesigner(&m_Storage->QuadManager); }
		Designer2DDrawOnDestroy<TransformQuadDesigner> DrawQuadT() { return Designer2DDrawOnDestroy(CreateQuadDesignerT()); }

		UnitQuadDesigner CreateQuadDesigner() { return UnitQuadDesigner(&m_Storage->QuadManager); }
		Designer2DDrawOnDestroy<UnitQuadDesigner> DrawQuad() { return Designer2DDrawOnDestroy(CreateQuadDesigner()); }

	public:
		EngineAPI& Engine() { return *m_EngineAPI; }
		Ref<EngineAPI> RefEngine() { return m_EngineAPI; }
		Renderer2DStorage& Storage() { return *m_Storage; }

	private:
		Ref<EngineAPI> m_EngineAPI;
		Scope<Renderer2DStorage> m_Storage = nullptr;
	};
}
