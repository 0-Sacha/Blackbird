#include "SceneCamera.h"

namespace Blackbird
{

	void SceneCamera::SetOrthographic(float size, float nearClip, float farClip)
	{
		m_OrthographicSize = size;
		m_OrthographicNearClip = nearClip;
		m_OrthographicFarClip = farClip;

		RecalculateProjection();
	}

	void SceneCamera::SetViewportSize(std::uint32_t width, std::uint32_t height)
	{
		m_AspectRatio = (float)width / (float)height;

		RecalculateProjection();
	}

	void SceneCamera::RecalculateProjection()
	{
		float orthoLeft = -m_OrthographicSize * m_AspectRatio * 0.5f;
		float orthoRight = m_OrthographicSize * m_AspectRatio * 0.5f;
		float orthoBottom = -m_OrthographicSize * 0.5f;
		float orthoTop = m_OrthographicSize * 0.5f;

		m_Projection = glm::ortho(orthoLeft, orthoRight, orthoTop, orthoBottom, m_OrthographicNearClip, m_OrthographicFarClip);
	}

}
