#pragma once

#include "Blackbird/Core/Core.h"

#include "LittleECS/LittleECS.h"

namespace Blackbird
{
	class Scene2D;
	class Entity : public LECS::LiteEntity
	{
	public:
		friend bool operator==(Entity lhs, Entity rhs);

	public:
		Entity();
		Entity(Scene2D* scene, LECS::EntityId entityId);

		const Scene2D* GetScene() const
		{
			return m_Scene;
		}
		Scene2D* GetScene()
		{
			return m_Scene;
		}

	private:
		Scene2D* m_Scene;
	};

	inline bool operator==(Entity lhs, Entity rhs)
	{
		return lhs.m_EntityId == rhs.m_EntityId;
	}
}
