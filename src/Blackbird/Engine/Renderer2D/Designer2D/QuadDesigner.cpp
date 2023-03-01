#pragma once

#include "QuadDesigner.h"

#include "../Renderer2D.h"

namespace Blackbird
{
    void QuadDesignerManager::Init(Renderer2D& renderer)
	{
		// Quad VertexArray
		QuadVA = renderer.Engine().AssetFactory().CreateVertexArray();

		float squareVertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,	1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f,	1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f,	0.0f, 1.0f
		};

		std::shared_ptr<VertexBuffer> squareVertexBuffer = renderer.Engine().AssetFactory().CreateVertexBuffer(squareVertices, sizeof(squareVertices));
		BufferLayout squareLayout = {
			{ ShaderData::Type::Float3, "a_Position" },
			{ ShaderData::Type::Float2, "a_TexCoord" }
		};
		squareVertexBuffer->SetLayout(squareLayout);
		QuadVA->AddVertexBuffer(squareVertexBuffer);

		uint32_t squareIndices[] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<IndexBuffer> squareIndexBuffer = renderer.Engine().AssetFactory().CreateIndexBuffer(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		QuadVA->SetIndexBuffer(squareIndexBuffer);

		// Quad Shaders
		FlatColorShader = renderer.Engine().ShaderFactory().CreateFromPath("assets/shaders/FlatColor.glsl");
		TextureShader = renderer.Engine().ShaderFactory().CreateFromPath("assets/shaders/Texture.glsl");
		TextureShader->Bind();
		TextureShader->SetInt("u_Texture", 0);
	}

    void QuadDesignerManager::Release()
	{
		QuadVA = nullptr;

		FlatColorShader = nullptr;
		TextureShader = nullptr;
	}

	void QuadDesignerManager::BeginScene(const OrthographicCamera& camera)
	{
		FlatColorShader->Bind();
		FlatColorShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());

		TextureShader->Bind();
		TextureShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
	}

	void QuadDesignerManager::EndScene()
	{

	}

	static void DrawQuadColor(QuadDesigner& quad, Renderer2D& renderer)
    {
		auto& quadManager = renderer.Storage().QuadManager;

		quadManager.FlatColorShader->Bind();
		quadManager.FlatColorShader->SetFloat4("u_Color", quad.Color);

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), quad.Position);
        if (quad.Size != glm::vec2{ 1.0f, 1.0f })
		    transform = glm::scale(transform, glm::vec3(quad.Size, 1.0f));
        if (quad.Rotation != 0)
		    transform = glm::rotate(transform, quad.Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		quadManager.FlatColorShader->SetMat4("u_Transform", transform);

		quadManager.QuadVA->Bind();
		renderer.Engine().RendererCommand().DrawIndexed(quadManager.QuadVA);
	}

	static void DrawQuadTexture(QuadDesigner& quad, Renderer2D& renderer)
	{
		auto& quadManager = renderer.Storage().QuadManager;

		quadManager.TextureShader->Bind();
		quadManager.TextureShader->SetFloat4("u_Color", quad.Color);
		quadManager.TextureShader->SetFloat("u_TilingFactor", quad.TilingFactor);

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), quad.Position);
        if (quad.Size != glm::vec2{ 1.0f, 1.0f })
		    transform = glm::scale(transform, glm::vec3(quad.Size, 1.0f));
        if (quad.Rotation != 0)
		    transform = glm::rotate(transform, quad.Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		quadManager.TextureShader->SetMat4("u_Transform", transform);
		
        quad.Texture->Bind();

		quadManager.QuadVA->Bind();
		renderer.Engine().RendererCommand().DrawIndexed(quadManager.QuadVA);
	}

    void QuadDesigner::Draw(Renderer2D& renderer)
    {
        if (Texture == nullptr)
            return DrawQuadColor(*this, renderer);
        return DrawQuadTexture(*this, renderer);
    }
}
