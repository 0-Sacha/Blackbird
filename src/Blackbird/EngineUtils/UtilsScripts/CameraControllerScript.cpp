#include "CameraControllerScript.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Blackbird/Scene/Components.h"
#include "Blackbird/Scene/Scene2D.h"

namespace Blackbird
{
	CameraControllerScript::CameraControllerScript(Entity entity, IInput& input)
		: NativeScript(entity)
		, m_Input(input)
	{
	}

	void CameraControllerScript::OnUpdate(TimeStep ts)
	{
		glm::mat4& transform = Get<TransformComponent>().Transform;

		if (m_Input.IsKeyPressed(KeyboardKey::A))
			transform = glm::translate(transform, glm::vec3{ m_CameraTranslationSpeed * ts, 0, 0 });
		else if (m_Input.IsKeyPressed(KeyboardKey::D))
			transform = glm::translate(transform, glm::vec3{ -m_CameraTranslationSpeed * ts, 0, 0 });
		else if (m_Input.IsKeyPressed(KeyboardKey::W))
			transform = glm::translate(transform, glm::vec3{ 0, m_CameraTranslationSpeed * ts, 0 });
		else if (m_Input.IsKeyPressed(KeyboardKey::S))
			transform = glm::translate(transform, glm::vec3{ 0, -m_CameraTranslationSpeed * ts, 0 });

		if (m_HasRotation)
		{
			if (m_Input.IsKeyPressed(KeyboardKey::Q))
				transform = glm::rotate(transform, m_CameraRotationSpeed * ts, glm::vec3(0, 0, 1));
			if (m_Input.IsKeyPressed(KeyboardKey::E))
				transform = glm::rotate(transform, -m_CameraRotationSpeed * ts, glm::vec3(0, 0, 1));
		}

		m_CameraTranslationSpeed = m_Entity.Get<SceneCameraComponent>().Camera.GetOrthographicSize();
	}

	void CameraControllerScript::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseScrolledEvent>(BLACKBIRD_BIND_EVENT(CameraControllerScript::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(BLACKBIRD_BIND_EVENT(CameraControllerScript::OnWindowResize));
	}

	bool CameraControllerScript::OnMouseScrolled(MouseScrolledEvent& event)
	{
		SceneCamera& sceneCamera = m_Entity.Get<SceneCameraComponent>().Camera;
		sceneCamera.SetOrthographicSize(sceneCamera.GetOrthographicSize() - event.GetYOffset() * 0.25f);
		return false;
	}

	bool CameraControllerScript::OnWindowResize(WindowResizeEvent& event)
	{
		// TODO : maybe resize here
		return false;
	}

	bool CameraControllerScript::OnMouseMouved(MouseMouvedEvent& event)
	{
		return false;
	}

}
