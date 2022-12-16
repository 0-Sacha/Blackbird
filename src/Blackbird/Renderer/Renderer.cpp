
#include "Blackbirdpch.h"

#include "Renderer.h"


namespace Blackbird {

	void Renderer::BeginScene()
	{
		
	}

	void Renderer::EndScene()
	{
		
	}

	void Renderer::Submit(const Ref<VertexArray>& VertexArray)
	{
		VertexArray->Bind();
		RendererCommand::DrawIndexed(VertexArray);
	}

}