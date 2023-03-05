#pragma once

#include "Blackbird/Engine/Camera/OrthographicCamera.h"

#include "Blackbird/EngineDetail/Utils/TimeStep.h"
#include "Blackbird/EngineDetail/Event/ApplicationEvent.h"
#include "Blackbird/EngineDetail/Event/MouseEvent.h"

#include "Blackbird/EngineDetail/Input/IInput.h"

namespace Blackbird
{
	struct OrthographicCameraBounds
	{
		float Left, Right;
		float Bottom, Top;

		float GetWidth() { return Right - Left; }
		float GetHeight() { return Top - Bottom; }
	};

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(IInput& input, float aspectRatio);

	public:
		void OnUpdate(TimeStep ts);

	public:
		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }
		OrthographicCameraBounds GetBoumds() { return m_CameraBounds; }
		float GetZoomLevel() const { return m_ZoomLevel; }

		void EnableRotation() { m_HasRotation = true; }
		void DisableRotation() { m_HasRotation = false; }

	public:
		void SetZoomLevel(float level)			{ m_ZoomLevel = level; CalculateProjection();}
		void SetAspectRatio(float aspectRatio)	{ m_AspectRatio = aspectRatio; CalculateProjection(); }
		void SetAspectRatio(std::uint32_t width, std::uint32_t height)	{ m_AspectRatio = (float)width / height; CalculateProjection(); }

	private:
		void CalculateProjection();

	public:
		void OnEvent(Event& event);

	private:
		bool OnMouseScrolled(MouseScrolledEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);
		bool OnMouseMouved(MouseMouvedEvent& event);

	private:
		IInput& m_Input;
		
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCameraBounds m_CameraBounds;
		OrthographicCamera m_Camera;

		bool m_HasRotation;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 5.0f;
		float m_CameraRotationSpeed = 50.0f;
	};

}
