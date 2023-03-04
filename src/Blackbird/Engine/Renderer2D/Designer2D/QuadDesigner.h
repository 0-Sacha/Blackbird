#pragma once

#include "IDesigner2D.h"

#include "Blackbird/Engine/Asset/VertexArray.h"
#include "Blackbird/Engine/Asset/VertexBuffer.h"
#include "Blackbird/Engine/Texture/Texture.h"
#include "Blackbird/Engine/Shader/Shader.h"

#include "../BatchBuffer2D.h"
#include "../BatchTextureSlot.h"

#include "../Statistics2D.h"

#include "glm/glm.hpp"

namespace Blackbird
{
    class QuadStatistics : public Statistics2D
    {
    public:
        std::uint32_t QuadCount = 0;

    public:
        void Reset() override { Statistics2D::Reset(); QuadCount = 0; }

	public:
		std::uint32_t GetVerticiesCount() override  { return QuadCount * 4; }
		std::uint32_t GetIndiciesCount() override   { return QuadCount * 6; }
	};

    class QuadDesignerManager;

    class QuadDesigner : public IDesigner2D
    {
	public:
        struct Vertex
        {
            glm::vec3 Position;
			glm::vec4 Color;
			glm::vec2 TexCoord;
			float TexIndex;
			float TilingFactor;
        };

	public:
        QuadDesigner(IDesigner2DManager* defaultRenderer = nullptr)
			: IDesigner2D(defaultRenderer)
		{}

    public:
        glm::vec3 Position = { 0.0f, 0.0f, 0.0f };
        glm::vec2 Size = { 1.0f, 1.0f };
        float Rotation = 0.0f;

        Ref<Texture2D> QuadTexture = nullptr;
        float TilingFactor = 1.0f;

        glm::vec4 Color = glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f };

    public:
        QuadDesigner& SetPosition(glm::vec3 pos) { Position = pos; return *this; }
        QuadDesigner& SetPosition(glm::vec2 pos) { Position = glm::vec3(pos, 0.0f); return *this; }
        QuadDesigner& SetSize(glm::vec2 size) { Size = size; return *this; }
        QuadDesigner& SetRotation(float rotation) { Rotation = rotation; return *this; }

        QuadDesigner& SetTexture(const Ref<Texture2D>& texture) { QuadTexture = texture; return *this; }
        QuadDesigner& SetTilingFactor(float tilingFactor) { TilingFactor = tilingFactor; return *this; }

        QuadDesigner& SetColor(glm::vec4 color) { Color = color; return *this; }

	public:
        glm::mat4 GetTransform()
        {
            glm::mat4 transform = glm::translate(glm::mat4(1.0f), Position);
            if (Size != glm::vec2{ 1.0f, 1.0f })
                transform = glm::scale(transform, glm::vec3(Size, 1.0f));
            if (Rotation != 0)
                transform = glm::rotate(transform, Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
            return transform;
        }

    public:
        void Draw(IDesigner2DManager& manager) override;
        void Draw(QuadDesignerManager& renderer);

		void DrawInstant(IDesigner2DManager& manager) override;
		void DrawInstant(QuadDesignerManager& renderer);
    };

    class QuadDesignerManager : public IDesigner2DManager 
    {
	public:
        static constexpr std::size_t NUMBER_OF_QUAD_BATCH = 10'000;
        using BatchBuffer2DType = BatchBuffer2D<typename QuadDesigner::Vertex, 4, 6>;

	public:
        QuadDesignerManager(Renderer2D& renderer, std::size_t numberOfQuadBatch = NUMBER_OF_QUAD_BATCH)
            : IDesigner2DManager(renderer)
            , BatchBuffer(numberOfQuadBatch)
        {}

    public:
        void Init() override;
        void Release() override;
    
	public:
		void BeginScene(const OrthographicCamera& camera) override;
		void Flush() override;
		void EndScene() override;

    public:
        BatchBuffer2DType BatchBuffer;
        BatchTextureSlot BatchTexture;
        
		Ref<VertexArray> QuadVA;
		Ref<VertexBuffer> QuadVB;
		Ref<Shader> BatchShader;
		Ref<Texture2D> WhiteTexture;

        QuadStatistics Stats;
    };
}
