#pragma once

#include "Blackbird/Engine/Renderer/RendererAPI.h"

namespace Blackbird::Platform::OpenGL
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		void Init() override;
		void Shutdown() override;

		void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height) override;

	public:
		void SetClearColor(const glm::vec4& color) override;
		void Clear() override;

		void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}
