#pragma once

#include "Entity.h"
#include "Blackbird/EngineDetail/Event/AllEvent.h"
#include "Blackbird/EngineDetail/Utils/TimeStep.h"

namespace Blackbird
{

	class NativeScript
	{
	public:
		NativeScript(Entity entity)
			: m_Entity(entity)
		{}

	public:
		virtual ~NativeScript() = default;

	public:
		virtual void OnBind() {}
		virtual void OnRelease() {}

		virtual void OnUpdate(TimeStep ts) {}
		virtual void OnEvent(Event& event) {}

	public:
		template<typename T>
		inline T& Get()
		{
			return m_Entity.Get<T>();
		}

	protected:
		Entity m_Entity;
	};

}
