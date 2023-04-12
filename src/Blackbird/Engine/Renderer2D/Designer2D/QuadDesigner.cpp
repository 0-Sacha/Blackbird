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

		QuadVB = assetFactory.CreateVertexBuffer(BatchBuffer.GetMaxVerticies() * sizeof(IQuadDesigner::Vertex));
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
		BatchShader = shaderFactory.CreateFromPath("../Blackbird/Assets/shaders/Texture.glsl");
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

	void QuadDesignerManager::BeginScene(const glm::mat4& viewProjectionMatrix)
	{
		BatchShader->Bind();
		BatchShader->SetMat4("u_ViewProjection", viewProjectionMatrix);

		BatchBuffer.Reset();
		BatchTexture.Reset();
	}

	void QuadDesignerManager::EndScene()
	{
		Flush();
	}

	void QuadDesignerManager::Flush()
	{
		Stats.DrawCall++;

		BatchTexture.BindAllTexture();
		QuadVB->SetData(BatchBuffer.GetData(), BatchBuffer.GetVerticiesSize());
		QuadVA->Bind();
		m_Renderer2D.Engine().RendererCommand().DrawIndexed(QuadVA, BatchBuffer.GetIndiciesCount());

		BatchBuffer.Reset();
		BatchTexture.Reset();
	}


	void IQuadDesigner::Draw(IDesigner2DManager& manager)
	{
		QuadDesignerManager* asQuadManager = dynamic_cast<QuadDesignerManager*>(&manager);
		if (asQuadManager != nullptr)
			return Draw(*asQuadManager);
		BLKBID_WARN("Give a IDesigner2DManager to a QuadDesigner which is not a QuadDesignerManager");
	}

    void IQuadDesigner::Draw(QuadDesignerManager& manager)
    {
		if (manager.BatchBuffer.CanAddObject() == false)
			manager.Flush();

		Ref<Texture2D> texture = QuadTexture == nullptr ? manager.WhiteTexture : QuadTexture;
		std::uint32_t texIndex;
		if (manager.BatchTexture.AddTexture(texture, texIndex) == false)
		{
			manager.Flush();
			manager.BatchTexture.AddTexture(texture, texIndex);
		}

		glm::mat4 transfrom = GetTransform();

		static constexpr glm::vec4 QUAD_VERTICIES_POSITION[4] = {
			{ -0.5f, -0.5f, 0.0f, 1.0f },
			{  0.5f, -0.5f, 0.0f, 1.0f },
			{  0.5f,  0.5f, 0.0f, 1.0f },
			{ -0.5f,  0.5f, 0.0f, 1.0f }
		};

		const glm::vec2& texCoordsMin = texture->GetTexCoordsMin();
		const glm::vec2& texCoordsMax = texture->GetTexCoordsMax();

		IQuadDesigner::Vertex vertex{ transfrom * QUAD_VERTICIES_POSITION[0], Color, { texCoordsMin.x, texCoordsMin.y }, texIndex, TilingFactor };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = transfrom * QUAD_VERTICIES_POSITION[1];
		vertex.TexCoord = { texCoordsMax.x, texCoordsMin.y };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = transfrom * QUAD_VERTICIES_POSITION[2];
		vertex.TexCoord = { texCoordsMax.x, texCoordsMax.y };
		manager.BatchBuffer.PushBackVertex(vertex);

		vertex.Position = transfrom * QUAD_VERTICIES_POSITION[3];
		vertex.TexCoord = { texCoordsMin.x, texCoordsMax.y };
		manager.BatchBuffer.PushBackVertex(vertex);

		manager.BatchBuffer.ObjectAdded();

		manager.Stats.QuadCount++;
    }


	static void DrawQuadColorInstant(IQuadDesigner& quad, QuadDesignerManager& manager)
	{
		// FIXME
		// manager.FlatColorShader->Bind();
		// manager.FlatColorShader->SetFloat4("u_Color", quad.Color);
		// manager.FlatColorShader->SetMat4("u_Transform", quad.GetTransform());

		manager.QuadVA->Bind();
		manager.GetRenderer2D().Engine().RendererCommand().DrawIndexed(manager.QuadVA);

		manager.Stats.QuadCount++;
		manager.Stats.DrawCall++;
	}

	static void DrawQuadTextureInstant(IQuadDesigner& quad, QuadDesignerManager& manager)
	{
		// FIXME
		// manager.TextureShader->Bind();
		// manager.TextureShader->SetFloat4("u_Color", quad.Color);
		// manager.TextureShader->SetFloat("u_TilingFactor", quad.TilingFactor);
		// manager.TextureShader->SetMat4("u_Transform", quad.GetTransform());

		quad.QuadTexture->Bind();
		manager.QuadVA->Bind();
		manager.GetRenderer2D().Engine().RendererCommand().DrawIndexed(manager.QuadVA);

		manager.Stats.QuadCount++;
		manager.Stats.DrawCall++;
	}


	void IQuadDesigner::DrawInstant(IDesigner2DManager& manager)
	{
		QuadDesignerManager* asQuadManager = dynamic_cast<QuadDesignerManager*>(&manager);
		if (asQuadManager != nullptr)
			return DrawInstant(*asQuadManager);
		BLKBID_WARN("Give a IDesigner2DManager to a QuadDesigner which is not a QuadDesignerManager");
	}

	void IQuadDesigner::DrawInstant(QuadDesignerManager& manager)
	{
		if (QuadTexture == nullptr)
			return DrawQuadColorInstant(*this, manager);
		return DrawQuadColorInstant(*this, manager);
	}
}
