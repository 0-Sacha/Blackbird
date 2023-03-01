#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class IDesigner2D;

	class S_Renderer2D
	{
	public:
		static void BeginScene(OrthographicCamera& camera) { StaticContext::GetRenderer2D().BeginScene(camera); }
		static void EndScene() { StaticContext::GetRenderer2D().EndScene(); }

	public:
		static QuadDesigner CreateQuadDesigner() { return StaticContext::GetRenderer2D().CreateQuadDesigner(); }
	};
}
