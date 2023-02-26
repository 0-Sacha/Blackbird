#include "Renderer2D.h"

#include "Renderer2DStorage/Renderer2DStorage.h"
#include "Blackbird/Engine/Renderer/RendererCommand.h"

namespace Blackbird
{
	void Renderer2D::Init()
	{
		Storage = new Renderer2DUtils::Renderer2DStorage();
		Storage->Init();
	}

	void Renderer2D::Shutdown()
	{
		delete Storage;
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		Storage->Shaders.FlatColorShader->Bind();
		Storage->Shaders.FlatColorShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());

		Storage->Shaders.TextureShader->Bind();
		Storage->Shaders.TextureShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
	}

	void Renderer2D::EndScene()
	{

	}

}
