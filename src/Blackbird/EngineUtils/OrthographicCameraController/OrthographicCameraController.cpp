#include "OrthographicCameraController.h"

#include "Blackbird/Engine/Static/S_Input.h"

namespace Blackbird
{
	OrthographicCameraController::OrthographicCameraController(IInput& input, float aspectRatio, bool hasRotation)
		: m_Input(input)
		, m_AspectRatio(aspectRatio)
		, m_CameraBounds{ -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel }
		, m_Camera(m_CameraBounds.Left, m_CameraBounds.Right, m_CameraBounds.Bottom, m_CameraBounds.Top)
		, m_HasRotation(hasRotation)
	{
	}

	void OrthographicCameraController::OnUpdate(TimeStep ts)
	{
		float updateSin = sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;
		float updateCos = cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * ts;

		if(m_Input.IsKeyPressed(KeyboardKey::A)) {
			m_CameraPosition.x -= updateCos;
			m_CameraPosition.y -= updateSin;
		} else if(m_Input.IsKeyPressed(KeyboardKey::D)) {
			m_CameraPosition.x += updateCos;
			m_CameraPosition.y += updateSin;
		} else if (m_Input.IsKeyPressed(KeyboardKey::W)) {
			m_CameraPosition.x -= updateSin;
			m_CameraPosition.y += updateCos;
		} else if (m_Input.IsKeyPressed(KeyboardKey::S)) {
			m_CameraPosition.x += updateSin;
			m_CameraPosition.y -= updateCos;
		}

		if(m_HasRotation)
		{
			if (m_Input.IsKeyPressed(KeyboardKey::Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			if (m_Input.IsKeyPressed(KeyboardKey::E))
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

	void OrthographicCameraController::CalculateProjection()
	{
		m_CameraBounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.SetProjection(m_CameraBounds.Left, m_CameraBounds.Right, m_CameraBounds.Bottom, m_CameraBounds.Top);
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
		CalculateProjection();
		return false;
	}

	bool OrthographicCameraController::OnWindowResize(WindowResizeEvent& event)
	{
		m_AspectRatio = (float)event.GetWidth() / (float)event.GetHeight();
		CalculateProjection();
		return false;
	}

	bool OrthographicCameraController::OnMouseMouved(MouseMouvedEvent& event)
	{
		return false;
	}

}
