#pragma once

#include "Entity.h"
// #include "Scene2D.h"

namespace Blackbird
{
	inline Entity::Entity()
		: LECS::LiteEntity()
		, m_Scene(nullptr)
	{}

	inline Entity::Entity(Scene2D* scene, LECS::EntityId entityId)
		: LECS::LiteEntity(&scene->Registry(), entityId)
		, m_Scene(scene)
	{}
}
