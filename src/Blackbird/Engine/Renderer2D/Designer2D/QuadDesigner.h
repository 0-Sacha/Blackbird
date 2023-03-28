#pragma once

#include "IDesigner2D.h"

#include "Blackbird/Engine/Asset/VertexArray.h"
#include "Blackbird/Engine/Asset/VertexBuffer.h"
#include "Blackbird/Engine/Texture/Texture.h"
#include "Blackbird/Engine/Shader/Shader.h"

#include "../BatchBuffer2D.h"
#include "../BatchTextureSlot.h"

#include "../Statistics2D.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Blackbird
{
    class QuadStatistics : public Statistics2D
    {
    public:
        ~QuadStatistics() override = default;

    public:
        std::uint32_t QuadCount = 0;

    public:
        void Reset() override { Statistics2D::Reset(); QuadCount = 0; }

	public:
		std::uint32_t GetVerticiesCount() override  { return QuadCount * 4; }
		std::uint32_t GetIndiciesCount() override   { return QuadCount * 6; }
	};

    class QuadDesignerManager;

    class IQuadDesigner : public IDesigner2D
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
        IQuadDesigner(IDesigner2DManager* defaultRenderer = nullptr)
			: IDesigner2D(defaultRenderer)
		{}

		~IQuadDesigner() override = default;

    public:
        Ref<Texture2D> QuadTexture = nullptr;
        float TilingFactor = 1.0f;
        glm::vec4 Color = glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f };

	public:
        virtual glm::mat4 GetTransform() = 0;

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
        using BatchBuffer2DType = BatchBuffer2D<typename IQuadDesigner::Vertex, 4, 6>;

	public:
        QuadDesignerManager(Renderer2D& renderer, std::size_t numberOfQuadBatch = NUMBER_OF_QUAD_BATCH)
            : IDesigner2DManager(renderer)
            , BatchBuffer(numberOfQuadBatch)
        {}

        ~QuadDesignerManager() override = default;

    public:
        void Init() override;
        void Release() override;
    
	public:
		void BeginScene(const glm::mat4& viewProjectionMatrix) override;
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

    class TransformQuadDesigner : public IQuadDesigner
    {
	public:
        glm::mat4 Tranform{ 1.0f };

	public:
        TransformQuadDesigner(IDesigner2DManager* defaultRenderer = nullptr)
			: IQuadDesigner(defaultRenderer)
		{}

        ~TransformQuadDesigner() override = default;

	public:
		glm::mat4 GetTransform() override
		{
            return Tranform;
		}

	public:
		TransformQuadDesigner& SetTranform(const glm::mat4& transform) { Tranform = transform; return *this; }
		TransformQuadDesigner& SetTexture(const Ref<Texture2D>& texture) { QuadTexture = texture; return *this; }
		TransformQuadDesigner& SetTilingFactor(float tilingFactor) { TilingFactor = tilingFactor; return *this; }
		TransformQuadDesigner& SetColor(glm::vec4 color) { Color = color; return *this; }
    };

    class UnitQuadDesigner : public IQuadDesigner
    {
    public:
        glm::vec3 Position = { 0.0f, 0.0f, 0.0f };
        glm::vec2 Size = { 1.0f, 1.0f };
        float Rotation = 0.0f;

	public:
        UnitQuadDesigner(IDesigner2DManager* defaultRenderer = nullptr)
			: IQuadDesigner(defaultRenderer)
		{}

		~UnitQuadDesigner() override = default;

    public:
        glm::mat4 GetTransform() override
        {
            glm::mat4 transform = glm::translate(glm::mat4(1.0f), Position);
            if (Size != glm::vec2{ 1.0f, 1.0f })
                transform = glm::scale(transform, glm::vec3(Size, 1.0f));
            if (Rotation != 0)
                transform = glm::rotate(transform, Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
            return transform;
        }

    public:
        UnitQuadDesigner& SetPosition(glm::vec3 pos) { Position = pos; return *this; }
        UnitQuadDesigner& SetPosition(glm::vec2 pos) { Position = glm::vec3(pos, 0.0f); return *this; }
        UnitQuadDesigner& SetSize(glm::vec2 size) { Size = size; return *this; }
        UnitQuadDesigner& SetRotation(float rotation) { Rotation = rotation; return *this; }
		UnitQuadDesigner& SetTexture(const Ref<Texture2D>& texture) { QuadTexture = texture; return *this; }
		UnitQuadDesigner& SetTilingFactor(float tilingFactor) { TilingFactor = tilingFactor; return *this; }
		UnitQuadDesigner& SetColor(glm::vec4 color) { Color = color; return *this; }
    };
}
