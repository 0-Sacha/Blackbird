#pragma once

#include "Blackbird/Scene/NativeScript.h"

#include "Blackbird/EngineDetail/Utils/TimeStep.h"
#include "Blackbird/EngineDetail/Event/ApplicationEvent.h"
#include "Blackbird/EngineDetail/Event/MouseEvent.h"

#include "Blackbird/EngineDetail/Input/IInput.h"

namespace Blackbird
{

	class CameraControllerScript final : public NativeScript
	{
	public:
		CameraControllerScript(Entity entity, IInput& input);
		~CameraControllerScript() override = default;

	public:
		void OnUpdate(TimeStep ts) override;
		void OnEvent(Event& event) override;

	public:
		void EnableRotation() { m_HasRotation = true; }
		void DisableRotation() { m_HasRotation = false; }

	private:
		bool OnMouseScrolled(MouseScrolledEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);
		bool OnMouseMouved(MouseMouvedEvent& event);

	private:
		IInput& m_Input;
		float m_CameraTranslationSpeed = 2.0f;
		bool m_HasRotation;
		float m_CameraRotationSpeed = 0.2f;
	};

}
