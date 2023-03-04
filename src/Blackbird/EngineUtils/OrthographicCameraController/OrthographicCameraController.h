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
		OrthographicCameraController(IInput& input, float aspectRatio, bool hasRotation);

	public:
		void OnUpdate(TimeStep ts);

	public:
		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }

		float GetZoomLevel() const		{ return m_ZoomLevel; }
		void SetZoomLevel(float level)	{ m_ZoomLevel = level; CalculateProjection();}

		OrthographicCameraBounds GetBoumds() { return m_CameraBounds; }
	
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
		float m_CameraRotationSpeed = 180.0f;
	};

}
