#pragma once

#include "Blackbird/Engine/Asset/VertexArray.h"

#include <glm/glm.hpp>

namespace Blackbird
{
	class IRendererCommand
	{
	public:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

	public:
		virtual void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height) = 0;
		virtual inline void SetClearColor(const glm::vec4& color) = 0;
		virtual inline void Clear() = 0;

		virtual inline void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) = 0;
	};
}
