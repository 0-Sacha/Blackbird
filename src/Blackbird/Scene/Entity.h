#pragma once

#include "Blackbird/Core/Core.h"

#include "entt/entt.hpp"

namespace Blackbird
{

	class Scene2D;
	class Entity
	{
	public:
		friend bool operator==(Entity lhs, Entity rhs);

	public:
		Entity()
			: m_EntityHandle(entt::null)
			, m_Scene(nullptr)
		{}

		Entity(entt::entity handle, Scene2D* scene)
			: m_EntityHandle(handle)
			, m_Scene(scene)
		{}

	public:
		template<typename T>					inline bool HasComponent();
		template<typename T>					inline T& GetComponent();
		template<typename T, typename... Args>	inline T& AddComponent(Args&&... args);
		template<typename T>					inline void RemoveComponent();

		operator bool ()
		{
			return m_EntityHandle != entt::null;
		}

	private:
		entt::entity m_EntityHandle;
		Scene2D* m_Scene;
	};

	inline bool operator==(Entity lhs, Entity rhs)
	{
		return lhs.m_EntityHandle == rhs.m_EntityHandle;
	}

}
