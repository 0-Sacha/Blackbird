#pragma once

#include "IDesigner2D.h"

#include "Blackbird/Engine/Asset/VertexArray.h"
#include "Blackbird/Engine/Texture/Texture.h"
#include "Blackbird/Engine/Shader/Shader.h"

#include "glm/glm.hpp"

namespace Blackbird
{
    class QuadDesigner : public IDesigner2D
    {
	public:
        QuadDesigner(Renderer2D* defaultRenderer = nullptr)
			: IDesigner2D(defaultRenderer)
		{}

    public:
        glm::vec3 Position = { 0.0f, 0.0f, 0.0f };
        glm::vec2 Size = { 1.0f, 1.0f };
        float Rotation = 0.0f;

        Ref<Texture2D> Texture = nullptr;
        float TilingFactor = 1.0f;

        glm::vec4 Color = glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f };

    public:
        QuadDesigner& SetPosition(glm::vec3 pos) { Position = pos; return *this; }
        QuadDesigner& SetPosition(glm::vec2 pos) { Position = glm::vec3(pos, 0.0f); return *this; }
        QuadDesigner& SetSize(glm::vec2 size) { Size = size; return *this; }
        QuadDesigner& SetRotation(float rotation) { Rotation = rotation; return *this; }

        QuadDesigner& SetTexture(const Ref<Texture2D>& texture) { Texture = texture; return *this; }
        QuadDesigner& SetTilingFactor(float tilingFactor) { TilingFactor = tilingFactor; return *this; }

        QuadDesigner& SetColor(glm::vec4 color) { Color = color; return *this; }

    public:
        void Draw(Renderer2D& renderer) override;
    };

    class QuadDesignerManager : public IDesigner2DManager 
    {
    public:
        void Init(Renderer2D& renderer) override;
        void Release() override;
    
	public:
		void BeginScene(const OrthographicCamera& camera) override;
		void EndScene() override;

    public:
		Ref<VertexArray> QuadVA;
		Ref<Shader> FlatColorShader;
		Ref<Shader> TextureShader;
    };
}
