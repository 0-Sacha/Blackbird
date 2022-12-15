#pragma once

#include <glm/glm.hpp>
#include "OpenGLCore/Renderer/Asset/VertexArray.h"

namespace OGLC {

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
		static void SetClearColor(const glm::vec4& color);
		static void Clear();

		static void DrawIndexed(const Ref<VertexArray>& vertexArray);

	private:
		static API s_API;
	};

}
