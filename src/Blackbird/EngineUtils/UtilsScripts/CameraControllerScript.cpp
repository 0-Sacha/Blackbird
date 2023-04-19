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
		glm::vec3& translation = Get<TransformComponent>().Translation;

		if (m_Input.IsKeyPressed(KeyboardKey::A))
			translation.x += m_CameraTranslationSpeed * ts;
		else if (m_Input.IsKeyPressed(KeyboardKey::D))
			translation.x -= m_CameraTranslationSpeed * ts;
		else if (m_Input.IsKeyPressed(KeyboardKey::W))
			translation.y += m_CameraTranslationSpeed * ts;
		else if (m_Input.IsKeyPressed(KeyboardKey::S))
			translation.y -= m_CameraTranslationSpeed * ts;

		if (m_HasRotation)
		{
			glm::vec3& rotation = Get<TransformComponent>().Rotation;
			if (m_Input.IsKeyPressed(KeyboardKey::Q))
				rotation.z += m_CameraRotationSpeed * ts;
			if (m_Input.IsKeyPressed(KeyboardKey::E))
				rotation.z -= m_CameraRotationSpeed * ts;
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
		sceneCamera.SetOrthographic(sceneCamera.GetOrthographicSize() - event.GetYOffset() * 0.25f, sceneCamera.GetOrthographicNearClip(), sceneCamera.GetOrthographicFarClip());
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
