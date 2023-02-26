#pragma once

#include "Blackbird/Engine/Asset/VertexArray.h"

#include <glm/glm.hpp>

#include "Blackbird/PlatformAPI.h"

namespace Blackbird
{
	class RendererCommand
	{
	public:
		static void Init()		{ PlatformAPI::GetInstance().GetRendererAPI().Init(); }
		static void Shutdown()	{ PlatformAPI::GetInstance().GetRendererAPI().Shutdown(); }

	public:
		static void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height)	{ PlatformAPI::GetInstance().GetRendererAPI().SetViewport(x, y, width, height); }
		static inline void SetClearColor(const glm::vec4& color)												{ PlatformAPI::GetInstance().GetRendererAPI().SetClearColor(color); }
		static inline void Clear()																				{ PlatformAPI::GetInstance().GetRendererAPI().Clear(); }
		static inline void DrawIndexed(const Ref<VertexArray>& vertexArray)										{ PlatformAPI::GetInstance().GetRendererAPI().DrawIndexed(vertexArray); }
	};
}
