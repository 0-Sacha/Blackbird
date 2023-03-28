#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Blackbird
{
	class Camera
	{
	public:
		Camera()
			: m_Projection{ 1.0f }
		{}

		Camera(const glm::mat4& projection)
			: m_Projection(projection)
		{}

		virtual ~Camera() = default;

	public:
		const glm::mat4& GetProjection() const { return m_Projection; }

	protected:
		glm::mat4 m_Projection;
	};
}
