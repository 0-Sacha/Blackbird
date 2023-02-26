

#include "OrthographicCameraController.h"

#include "Blackbird/EngineDetail/Input/Input.h"

namespace Blackbird {

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool hasRotation)
		: m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_HasRotation(hasRotation)
	{
	}

	void OrthographicCameraController::OnUpdate(TimeStep ts)
	{
		float updateSin = sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		float updateCos = cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;

		if(Input::IsKeyPressed(KeyboardKey::A)) {
			m_CameraPosition.x -= updateCos;
			m_CameraPosition.y -= updateSin;
		} else if(Input::IsKeyPressed(KeyboardKey::D)) {
			m_CameraPosition.x += updateCos;
			m_CameraPosition.y += updateSin;
		} else if (Input::IsKeyPressed(KeyboardKey::W)) {
			m_CameraPosition.x -= updateSin;
			m_CameraPosition.y += updateCos;
		} else if (Input::IsKeyPressed(KeyboardKey::S)) {
			m_CameraPosition.x += updateSin;
			m_CameraPosition.y -= updateCos;
		}

		if(m_HasRotation)
		{
			if (Input::IsKeyPressed(KeyboardKey::Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			if (Input::IsKeyPressed(KeyboardKey::E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;

			if (m_CameraRotation > 180.0f)
				m_CameraRotation -= 360.0f;
			else if (m_CameraRotation <= -180.0f)
				m_CameraRotation += 360.0f;

			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);
		m_CameraTranslationSpeed = m_ZoomLevel;
	}

	void OrthographicCameraController::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseScrolledEvent>(BLACKBIRD_BIND_EVENT(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(BLACKBIRD_BIND_EVENT(OrthographicCameraController::OnWindowResize));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& event)
	{
		m_ZoomLevel -= event.GetYOffset() * 0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResize(WindowResizeEvent& event)
	{
		m_AspectRatio = (float)event.GetWidth() / (float)event.GetHeight();
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

}