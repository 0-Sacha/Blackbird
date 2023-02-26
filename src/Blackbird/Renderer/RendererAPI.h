#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Blackbird/Renderer/Asset/VertexArray.h"

namespace Blackbird
{
	class RendererAPI
	{
	public: 
		enum class API
		{
			None,
			OpenGL
		};

	public:
		static inline API GetAPI() { return s_API; }

	public:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void SetViewport(std::uint32_t x, std::uint32_t y, std::uint32_t width, std::uint32_t height) = 0;

		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) = 0;

	private:
		static API s_API;
	};
}
