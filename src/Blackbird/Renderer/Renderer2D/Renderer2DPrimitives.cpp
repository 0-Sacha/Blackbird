#include "Renderer2D.h"

#include "Renderer2DStorage/Renderer2DStorage.h"
#include "Blackbird/Renderer/RendererCommand.h"

namespace Blackbird
{

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color)
	{
		glm::vec3 position3 = glm::vec3(position, 0.0f);
		DrawQuad(position3, size, rotation, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color)
	{
		Storage->Shaders.FlatColorShader->Bind();
		Storage->Shaders.FlatColorShader->SetFloat4("u_Color", color);

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position);
		transform = glm::scale(transform, glm::vec3(size, 1.0f));
		transform = glm::rotate(transform, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		Storage->Shaders.FlatColorShader->SetMat4("u_Transform", transform);

		Storage->Quad2D.QuadVA->Bind();
		RendererCommand::DrawIndexed(Storage->Quad2D.QuadVA);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture)
	{
		glm::vec3 position3 = glm::vec3(position, 0.0f);
		DrawQuad(position3, size, rotation, texture);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture)
	{
		Storage->Shaders.TextureShader->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position);
		transform = glm::scale(transform, glm::vec3(size, 1.0f));
		transform = glm::rotate(transform, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
		Storage->Shaders.TextureShader->SetMat4("u_Transform", transform);
		
		texture->Bind();

		Storage->Quad2D.QuadVA->Bind();
		RendererCommand::DrawIndexed(Storage->Quad2D.QuadVA);
	}

}
