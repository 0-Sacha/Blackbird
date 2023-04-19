#pragma once

#include "Blackbird/Engine/Camera/Camera.h"

namespace Blackbird
{
	class SceneCamera : public Camera
	{
	public:
		enum class ProjectionType
		{
			Perspective = 0,
			Orthographic = 1
		};

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
		ProjectionType GetProjectionType() const { return m_ProjectionType; }
		void SetProjectionType(ProjectionType projectionType) { m_ProjectionType = projectionType; }

		void SetViewportSize(std::uint32_t width, std::uint32_t height);
		void RecalculateProjection();

	public:

	public:
		void SetOrthographic(float size, float nearClip, float farClip);

		float GetOrthographicSize() { return m_OrthographicSize; }
		float GetOrthographicNearClip() { return m_OrthographicNearClip; }
		float GetOrthographicFarClip() { return m_OrthographicFarClip; }

	public:
		void SetPerspective(float verticalFOV, float nearClip, float farClip);

		float GetPerspectiveFOV() { return m_PerspectiveFOV; }
		float GetPerspectiveNearClip() { return m_PerspectiveNearClip; }
		float GetPerspectiveFarClip() { return m_PerspectiveFarClip; }

	private:
		ProjectionType m_ProjectionType = ProjectionType::Orthographic;
		float m_AspectRatio = 0.0f;

		float m_OrthographicSize = 10.0f;
		float m_OrthographicNearClip = -1.0f;
		float m_OrthographicFarClip = 1.0f;

		float m_PerspectiveFOV = glm::radians(45.0f);
		float m_PerspectiveNearClip = 0.010f;
		float m_PerspectiveFarClip = 10'000.0f;
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
