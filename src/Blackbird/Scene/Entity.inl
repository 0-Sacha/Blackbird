#pragma once

#include "Entity.h"
// #include "Scene2D.h"

namespace Blackbird
{

	template<typename T>
	inline bool Entity::HasComponent()
	{
		return m_Scene->Registry().any_of<T>(m_EntityHandle);
	}

	template<typename T>
	inline T& Entity::GetComponent()
	{
		BLACKBIRD_ASSERT(HasComponent<T>() == true, "This entity already doesn't have this component");

		return m_Scene->Registry().get<T>(m_EntityHandle);
	}

	template<typename T, typename... Args>
	inline T& Entity::AddComponent(Args&&... args)
	{
		BLACKBIRD_ASSERT(HasComponent<T>() == false, "This entity already has this component");

		return m_Scene->Registry().emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
	}

	template<typename T>
	inline void Entity::RemoveComponent()
	{
		BLACKBIRD_ASSERT(HasComponent<T>() == true, "This entity already doesn't have this component");

		m_Scene->Registry().remove()<T>(m_EntityHandle);
	}

}
