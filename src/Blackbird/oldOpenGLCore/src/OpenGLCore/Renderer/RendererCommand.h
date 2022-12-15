#pragma once

#include "RendererAPI.h"

namespace Spitfire {

	class RendererCommand
	{
	public:
		static inline void SetClearColor(const glm::vec4& color) {
			RendererAPI::SetClearColor(color);
		}

		static inline void Clear() {
			RendererAPI::Clear();
		}

		static inline void DrawIndexed(const Ref<VertexArray>& vertexArray) {
			RendererAPI::DrawIndexed(vertexArray);
		}
	};

}