#pragma once

#include "Blackbird/Engine/Camera/Camera.h"

namespace Blackbird
{
	class SceneCamera : public Camera
	{
	public:
		SceneCamera()
			: Camera(glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f))
		{}

		SceneCamera(float size, float nearClip, float farClip)
			: m_OrthographicSize(size)
			, m_OrthographicNearClip(nearClip)
			, m_OrthographicFarClip(farClip)
		{}

		~SceneCamera() override = default;

	public:
		void SetOrthographic(float size, float nearClip, float farClip);
		float GetOrthographicSize() { return m_OrthographicSize; }
		void SetOrthographicSize(float size) { m_OrthographicSize = size; RecalculateProjection(); }

		void SetViewportSize(std::uint32_t width, std::uint32_t height);
		void RecalculateProjection();

	private:
		float m_OrthographicSize = 10.0f;
		float m_OrthographicNearClip = -1.0f;
		float m_OrthographicFarClip = 1.0f;

		float m_AspectRatio = 0.0f;
	};

	/*
	class OrthographicSceneCamera : public SceneCamera
	{
	public:
		OrthographicSceneCamera();
		~OrthographicSceneCamera() override = default;
	};
	*/
}
