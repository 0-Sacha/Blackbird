#pragma once

#include "RendererAPI.h"

namespace Blackbird {

	class RendererCommand
	{
	public:
		static inline void Init()
		{
			s_RendererAPI->Init();
		}

		static inline void Shutdown()
		{
			s_RendererAPI->Shutdown();
		}

		static void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height)
		{
			s_RendererAPI->SetViewport(x, y, width, height);
		}
		
		static inline void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}

		static inline void Clear()
		{
			s_RendererAPI->Clear();
		}

		static inline void DrawIndexed(const Ref<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}

	private:
		static RendererAPI* s_RendererAPI;
	};
}
