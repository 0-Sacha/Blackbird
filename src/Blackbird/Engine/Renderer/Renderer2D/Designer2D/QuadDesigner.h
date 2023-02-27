#pragma once

#include "IDesigner2D.h"

namespace Blackbird
{
    class QuadDesigner : public IDesigner2D
    {
    public:
        glm::vec3 Position = { 0.0f, 0.0f, 0.0f };
        glm::vec2 Size = { 1.0f, 1.0f };
        float Rotation = 0.0f;

        Ref<Texture2D> Texture = nullptr;
        float TilingFactor = 1.0f;

        glm::vec4 Color = glm::vec4{ 1.0f, 1.0f, 1.0f, 1.0f };

    public:
        QuadDesigner& SetPosition(glm::vec3 pos) { Position = pos; return *this; }
        QuadDesigner& SetPosition(glm::vec2 pos) { Position = glm::vec3(pos, 1.0f); return *this; }
        QuadDesigner& SetSize(glm::vec2 size) { Size = size; return *this; }
        QuadDesigner& SetRotation(float rotation) { Rotation = rotation; return *this; }

        QuadDesigner& SetTexture(const Ref<Texture2D>& texture) { Texture = texture; return *this; }
        QuadDesigner& SetTilingFactor(float tilingFactor) { TilingFactor = tilingFactor; return *this; }

        QuadDesigner& SetColor(glm::vec4 color) { Color = color; return *this; }

    public:
        void Draw() override;
    };
}
