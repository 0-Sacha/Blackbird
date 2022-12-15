#pragma once

#include <glm/glm.hpp>

#include "Spitfire/Renderer/Asset/VertexArray.h"

namespace Spitfire {

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
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) = 0;

	private:
		static API s_API;
	};

}