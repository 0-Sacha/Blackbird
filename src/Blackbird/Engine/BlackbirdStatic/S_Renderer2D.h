#pragma once

#include "S_Application.h"

namespace Blackbird
{
	class IDesigner2D;

	class S_Renderer2D
	{
	public:
		static Renderer2D& Get()			{ return S_Application::GetRenderer2D(); }
		static Ref<Renderer2D>& GetRef()	{ return S_Application::GetRenderer2DRef(); }

	public:
		static void BeginScene(const Camera& camera, const glm::mat4& cameraTransform)	{ Get().BeginScene(camera, cameraTransform); }
		static void EndScene()															{ Get().EndScene(); }
		
	public:
		static Renderer2DStatistics GetStats()				{ return Get().GetStats();}
		static void ResetStats()							{ return Get().ResetStats(); }

	public:
		static TransformQuadDesigner CreateQuadDesignerT()					{ return Get().CreateQuadDesignerT(); }
		static Designer2DDrawOnDestroy<TransformQuadDesigner> DrawQuadT()	{ return Get().DrawQuadT(); }

		static UnitQuadDesigner CreateQuadDesigner()				{ return Get().CreateQuadDesigner(); }
		static Designer2DDrawOnDestroy<UnitQuadDesigner> DrawQuad() { return Get().DrawQuad(); }
	};
}
