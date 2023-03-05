#pragma once

#include "S_Application.h"

namespace Blackbird
{
	class IDesigner2D;

	class S_Renderer2D
	{
	public:
		static Renderer2D& Get() { return S_Application::GetRenderer2D(); }

	public:
		static void BeginScene(OrthographicCamera& camera)	{ Get().BeginScene(camera); }
		static void EndScene()								{ Get().EndScene(); }
		
	public:
		static Renderer2DStatistics GetStats()				{ return Get().GetStats();}
		static void ResetStats()							{ return Get().ResetStats(); }

	public:
		static QuadDesigner CreateQuadDesigner()				{ return Get().CreateQuadDesigner(); }
		static Designer2DDrawOnDestroy<QuadDesigner> DrawQuad() { return Get().DrawQuad(); }
	};
}
