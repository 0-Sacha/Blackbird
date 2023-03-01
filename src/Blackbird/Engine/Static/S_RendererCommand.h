#pragma once

#include "StaticContext.h"

namespace Blackbird
{
	class S_RendererCommand
	{
	public:
		static void Init()		{ StaticContext::Engine().RendererCommand().Init(); }
		static void Shutdown()	{ StaticContext::Engine().RendererCommand().Shutdown(); }

	public:
		static void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height)	{ StaticContext::Engine().RendererCommand().SetViewport(x, y, width, height); }
		static inline void SetClearColor(const glm::vec4& color)												{ StaticContext::Engine().RendererCommand().SetClearColor(color); }
		static inline void Clear()																				{ StaticContext::Engine().RendererCommand().Clear(); }
		static inline void DrawIndexed(const Ref<VertexArray>& vertexArray)										{ StaticContext::Engine().RendererCommand().DrawIndexed(vertexArray); }
	};
}
