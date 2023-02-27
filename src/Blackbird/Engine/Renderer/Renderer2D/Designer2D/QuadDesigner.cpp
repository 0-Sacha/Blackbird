#pragma once

#include "QuadDesigner.h"

#include "../Renderer2DStorage/Renderer2DStorage.h"
#include "Blackbird/Engine/Renderer/RendererCommand.h"

namespace Blackbird
{
	static void DrawQuadColor(QuadDesigner& quad)
    {
		Renderer2D::Storage->Shaders.FlatColorShader->Bind();
		Renderer2D::Storage->Shaders.FlatColorShader->SetFloat4("u_Color", quad.Color);

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), quad.Position);
        if (quad.Size != glm::vec2{ 1.0f, 1.0f })
		    transform = glm::scale(transform, glm::vec3(quad.Size, 1.0f));
        if (quad.Rotation != 0)
		    transform = glm::rotate(transform, quad.Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		Renderer2D::Storage->Shaders.FlatColorShader->SetMat4("u_Transform", transform);

		Renderer2D::Storage->Quad2D.QuadVA->Bind();
		RendererCommand::DrawIndexed(Renderer2D::Storage->Quad2D.QuadVA);
	}

	static void DrawQuadTexture(QuadDesigner& quad)
	{
		Renderer2D::Storage->Shaders.TextureShader->Bind();
		Renderer2D::Storage->Shaders.TextureShader->SetFloat4("u_Color", quad.Color);
		Renderer2D::Storage->Shaders.TextureShader->SetFloat("u_TilingFactor", quad.TilingFactor);

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), quad.Position);
        if (quad.Size != glm::vec2{ 1.0f, 1.0f })
		    transform = glm::scale(transform, glm::vec3(quad.Size, 1.0f));
        if (quad.Rotation != 0)
		    transform = glm::rotate(transform, quad.Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		Renderer2D::Storage->Shaders.TextureShader->SetMat4("u_Transform", transform);
		
        quad.Texture->Bind();

		Renderer2D::Storage->Quad2D.QuadVA->Bind();
		RendererCommand::DrawIndexed(Renderer2D::Storage->Quad2D.QuadVA);
	}

    void QuadDesigner::Draw()
    {
        if (Texture == nullptr)
            return DrawQuadColor(*this);
        return DrawQuadTexture(*this);
    }
}
