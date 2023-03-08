#pragma once

#include "Blackbird/Engine/IRendererCommand.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{
	class OpenGLRendererCommand : public IRendererCommand
	{
	public:
		~OpenGLRendererCommand() override = default;

	public:
		void Init() override;
		void Shutdown() override;

		void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height) override;

	public:
		void SetClearColor(const glm::vec4& color) override;
		void Clear() override;

		void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) override;
	};
}
