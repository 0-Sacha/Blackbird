#pragma once

#include "QuadDesigner.h"

#include "../Renderer2D.h"

namespace Blackbird
{
    void QuadDesignerManager::Init()
	{
		auto& assetFactory = m_Renderer2D.Engine().AssetFactory();

		// Quad VertexArray
		QuadVA = assetFactory.CreateVertexArray();

		QuadVB = assetFactory.CreateVertexBuffer(BatchBuffer.GetMaxVerticies() * sizeof(QuadDesigner::Vertex));
		BufferLayout squareLayout = {
			{ ShaderData::Type::Float3, "a_Position" },
			{ ShaderData::Type::Float4, "a_Color" },
			{ ShaderData::Type::Float2, "a_TexCoord" }
		};
		QuadVB->SetLayout(squareLayout);
		QuadVA->AddVertexBuffer(QuadVB);

		uint32_t* quadIndicies = new uint32_t[BatchBuffer.GetMaxIndicies()];
		uint32_t offset = 0;
		for (uint32_t i = 0; i + 5 < BatchBuffer.GetMaxIndicies(); i += 6)
		{
			quadIndicies[i + 0] = offset + 0;
			quadIndicies[i + 1] = offset + 1;
			quadIndicies[i + 2] = offset + 2;

			quadIndicies[i + 3] = offset + 2;
			quadIndicies[i + 4] = offset + 3;
			quadIndicies[i + 5] = offset + 0;
		
			offset += 4;
		}
		Ref<IndexBuffer> quadIB = assetFactory.CreateIndexBuffer(quadIndicies, BatchBuffer.GetMaxIndicies());
		QuadVA->SetIndexBuffer(quadIB);
		delete[] quadIndicies;


		// Quad Shaders
		auto& shaderFactory = m_Renderer2D.Engine().ShaderFactory();

		FlatColorShader = shaderFactory.CreateFromPath("assets/shaders/FlatColor.glsl");
		TextureShader = shaderFactory.CreateFromPath("assets/shaders/Texture.glsl");
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

		BatchBuffer.BeginScene();
	}

	void QuadDesignerManager::EndScene()
	{
		QuadVB->SetData(BatchBuffer.GetData(), BatchBuffer.GetVerticiesSize());
		Flush();
	}

	void QuadDesignerManager::Flush()
	{
		TextureShader->Bind();
		QuadVA->Bind();
		m_Renderer2D.Engine().RendererCommand().DrawIndexed(QuadVA, BatchBuffer.GetIndiciesCount());
	}

	static void DrawQuadColor(QuadDesigner& quad, QuadDesignerManager& manager)
    {
		QuadDesigner::Vertex vertex{ quad.Position, quad.Color, { 0.0f, 0.0f } };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = { quad.Position.x + quad.Size.x, quad.Position.y, 0.0f };
		vertex.TexCoord = { 1.0f, 0.0f };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = { quad.Position.x + quad.Size.x, quad.Position.y + quad.Size.y, 0.0f };
		vertex.TexCoord = { 1.0f, 1.0f };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = { quad.Position.x, quad.Position.y + quad.Size.y, 0.0f };
		vertex.TexCoord = { 0.0f, 1.0f };
		manager.BatchBuffer.PushBackVertex(vertex);

		manager.BatchBuffer.ObjectAdded();

		/*
		manager.FlatColorShader->Bind();
		manager.FlatColorShader->SetFloat4("u_Color", quad.Color);

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), quad.Position);
        if (quad.Size != glm::vec2{ 1.0f, 1.0f })
		    transform = glm::scale(transform, glm::vec3(quad.Size, 1.0f));
        if (quad.Rotation != 0)
		    transform = glm::rotate(transform, quad.Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		manager.FlatColorShader->SetMat4("u_Transform", transform);

		manager.QuadVA->Bind();
		manager.GetRenderer2D().Engine().RendererCommand().DrawIndexed(manager.QuadVA);
		*/
	}

	static void DrawQuadTexture(QuadDesigner& quad, QuadDesignerManager& manager)
	{
		manager.TextureShader->Bind();
		manager.TextureShader->SetFloat4("u_Color", quad.Color);
		manager.TextureShader->SetFloat("u_TilingFactor", quad.TilingFactor);

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), quad.Position);
        if (quad.Size != glm::vec2{ 1.0f, 1.0f })
		    transform = glm::scale(transform, glm::vec3(quad.Size, 1.0f));
        if (quad.Rotation != 0)
		    transform = glm::rotate(transform, quad.Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		manager.TextureShader->SetMat4("u_Transform", transform);
		
        quad.Texture->Bind();

		manager.QuadVA->Bind();
		manager.GetRenderer2D().Engine().RendererCommand().DrawIndexed(manager.QuadVA);
	}

	void QuadDesigner::Draw(IDesigner2DManager& manager)
	{
		QuadDesignerManager* asQuadManager = dynamic_cast<QuadDesignerManager*>(&manager);
		if (asQuadManager != nullptr)
			return Draw(*asQuadManager);
		BLACKBIRD_WARN("Give a IDesigner2DManager to a QuadDesigner which is not a QuadDesignerManager");
	}

    void QuadDesigner::Draw(QuadDesignerManager& manager)
    {
        if (Texture == nullptr)
            return DrawQuadColor(*this, manager);
        return DrawQuadTexture(*this, manager);
    }
}
