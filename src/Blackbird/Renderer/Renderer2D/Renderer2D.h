#pragma once

#include "Blackbird/Renderer/Camera/OrthographicCamera.h"
#include "Blackbird/Renderer/Texture/Texture.h"

namespace Blackbird::Renderer2DUtils
{
	struct Renderer2DStorage;
}

namespace Blackbird
{

	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

	public:
		//Primitives
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture);

	public:
		static inline Renderer2DUtils::Renderer2DStorage* Storage = nullptr;
	};

}
