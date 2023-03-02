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
			{ ShaderData::Type::Float2, "a_TexCoord" },
			{ ShaderData::Type::Float, "a_TexIndex" },
			{ ShaderData::Type::Float, "a_TilingFactor" }
		};
		QuadVB->SetLayout(squareLayout);
		QuadVA->AddVertexBuffer(QuadVB);

		const std::size_t quadIndiciesSize = BatchBuffer.GetMaxIndicies();
		uint32_t* quadIndicies = new uint32_t[quadIndiciesSize];
		uint32_t offset = 0;
		for (uint32_t i = 0; i + 5 < quadIndiciesSize; i += 6)
		{
			quadIndicies[i + 0] = offset + 0;
			quadIndicies[i + 1] = offset + 1;
			quadIndicies[i + 2] = offset + 2;

			quadIndicies[i + 3] = offset + 2;
			quadIndicies[i + 4] = offset + 3;
			quadIndicies[i + 5] = offset + 0;
		
			offset += 4;
		}
		Ref<IndexBuffer> quadIB = assetFactory.CreateIndexBuffer(quadIndicies, quadIndiciesSize);
		QuadVA->SetIndexBuffer(quadIB);
		delete[] quadIndicies;


		// Quad Shaders
		auto& shaderFactory = m_Renderer2D.Engine().ShaderFactory();
		BatchShader = shaderFactory.CreateFromPath("assets/shaders/Texture.glsl");
		BatchShader->Bind();

		const std::size_t samplerSize = BatchTexture.GetMaxTexturePerBatch();
		int32_t* samplers = new int32_t[samplerSize];
		for (std::size_t i = 0; i < samplerSize; ++i)
			samplers[i] = i;
		BatchShader->SetIntArray("u_Textures", samplers, samplerSize);

		auto& textureFactory = m_Renderer2D.Engine().TextureFactory();
		WhiteTexture = textureFactory.CreateTexture2DUniqueColor(0xff'ff'ff'ff);
	}

    void QuadDesignerManager::Release()
	{
		QuadVA = nullptr;

		BatchShader = nullptr;
	}

	void QuadDesignerManager::BeginScene(const OrthographicCamera& camera)
	{
		BatchShader->Bind();
		BatchShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());

		BatchBuffer.Reset();
		BatchTexture.Reset();
	}

	void QuadDesignerManager::EndScene()
	{
		BatchTexture.BindAllTexture();
		QuadVB->SetData(BatchBuffer.GetData(), BatchBuffer.GetVerticiesSize());
		Flush();
	}

	void QuadDesignerManager::Flush()
	{
		QuadVA->Bind();
		m_Renderer2D.Engine().RendererCommand().DrawIndexed(QuadVA, BatchBuffer.GetIndiciesCount());
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
		std::uint32_t texIndex;
		if (Texture == nullptr)
			manager.BatchTexture.AddTexture(manager.WhiteTexture, texIndex);
		else
			manager.BatchTexture.AddTexture(Texture, texIndex);

		glm::mat4 transfrom = GetTransform();

		static constexpr glm::vec4 QUAD_VERTICIES_POSITION[4] = {
			{ -0.5f, -0.5f, 0.0f, 1.0f },
			{  0.5f, -0.5f, 0.0f, 1.0f },
			{  0.5f,  0.5f, 0.0f, 1.0f },
			{ -0.5f,  0.5f, 0.0f, 1.0f }
		};

		manager.BatchBuffer.BeginObject();

		QuadDesigner::Vertex vertex{ transfrom * QUAD_VERTICIES_POSITION[0], Color, { 0.0f, 0.0f }, texIndex, TilingFactor };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = transfrom * QUAD_VERTICIES_POSITION[1];
		vertex.TexCoord = { 1.0f, 0.0f };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = transfrom * QUAD_VERTICIES_POSITION[2];
		vertex.TexCoord = { 1.0f, 1.0f };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = transfrom * QUAD_VERTICIES_POSITION[3];
		vertex.TexCoord = { 0.0f, 1.0f };
		manager.BatchBuffer.PushBackVertex(vertex);

		manager.BatchBuffer.EndObject();
    }


	static void DrawQuadColorInstant(QuadDesigner& quad, QuadDesignerManager& manager)
	{
		// FIXME
		// manager.FlatColorShader->Bind();
		// manager.FlatColorShader->SetFloat4("u_Color", quad.Color);
		// manager.FlatColorShader->SetMat4("u_Transform", quad.GetTransform());

		manager.QuadVA->Bind();
		manager.GetRenderer2D().Engine().RendererCommand().DrawIndexed(manager.QuadVA);
	}

	static void DrawQuadTextureInstant(QuadDesigner& quad, QuadDesignerManager& manager)
	{
		// FIXME
		// manager.TextureShader->Bind();
		// manager.TextureShader->SetFloat4("u_Color", quad.Color);
		// manager.TextureShader->SetFloat("u_TilingFactor", quad.TilingFactor);
		// manager.TextureShader->SetMat4("u_Transform", quad.GetTransform());

		quad.Texture->Bind();
		manager.QuadVA->Bind();
		manager.GetRenderer2D().Engine().RendererCommand().DrawIndexed(manager.QuadVA);
	}


	void QuadDesigner::DrawInstant(IDesigner2DManager& manager)
	{
		QuadDesignerManager* asQuadManager = dynamic_cast<QuadDesignerManager*>(&manager);
		if (asQuadManager != nullptr)
			return DrawInstant(*asQuadManager);
		BLACKBIRD_WARN("Give a IDesigner2DManager to a QuadDesigner which is not a QuadDesignerManager");
	}

	void QuadDesigner::DrawInstant(QuadDesignerManager& manager)
	{
		if (Texture == nullptr)
			return DrawQuadColorInstant(*this, manager);
		return DrawQuadColorInstant(*this, manager);
	}
}
