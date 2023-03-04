#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_RendererCommand
	{
	public:
		static IRendererCommand& Get() { return StaticContext::Engine().RendererCommand(); }

	public:
		static void Init()		{ Get().Init(); }
		static void Shutdown()	{ Get().Shutdown(); }

	public:
		static void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height)	{ Get().SetViewport(x, y, width, height); }
		static inline void SetClearColor(const glm::vec4& color)												{ Get().SetClearColor(color); }
		static inline void Clear()																				{ Get().Clear(); }
		static inline void DrawIndexed(const Ref<VertexArray>& vertexArray)										{ Get().DrawIndexed(vertexArray); }
	};
}
