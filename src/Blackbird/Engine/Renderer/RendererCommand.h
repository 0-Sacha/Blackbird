#pragma once

#include "Blackbird/Engine/Asset/VertexArray.h"

#include <glm/glm.hpp>

#include "Blackbird/EngineAPI.h"

namespace Blackbird
{
	class RendererCommand
	{
	public:
		static void Init()		{ EngineAPI::GetInstance().GetRendererCommand().Init(); }
		static void Shutdown()	{ EngineAPI::GetInstance().GetRendererCommand().Shutdown(); }

	public:
		static void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height)	{ EngineAPI::GetInstance().GetRendererCommand().SetViewport(x, y, width, height); }
		static inline void SetClearColor(const glm::vec4& color)												{ EngineAPI::GetInstance().GetRendererCommand().SetClearColor(color); }
		static inline void Clear()																				{ EngineAPI::GetInstance().GetRendererCommand().Clear(); }
		static inline void DrawIndexed(const Ref<VertexArray>& vertexArray)										{ EngineAPI::GetInstance().GetRendererCommand().DrawIndexed(vertexArray); }
	};
}
