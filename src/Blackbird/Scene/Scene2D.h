#pragma once

#include "Blackbird/EngineDetail/Utils/TimeStep.h"
#include "Blackbird/Engine/Renderer2D/Renderer2D.h"

#include "LittleECS/LittleECS.h"
#include "Entity.h"

namespace Blackbird
{
	class Entity;
	class Scene2D
	{
	public:
		friend Entity;

	public:
		Scene2D(Blackbird::Ref<Blackbird::Renderer2D>& renderer);
		~Scene2D();

	public:
		Entity CreateEntity(const std::string& name = "");

		void SetPrimatryCameraEntity(Entity camera) { m_PrimaryCameraEntity = camera; }
		Entity GetPrimatryCameraEntity() { return m_PrimaryCameraEntity; }
	
	private:
		LECS::Registry& Registry() { return m_Registry; }

	public:
		void OnViewportResize(std::uint32_t width, std::uint32_t height);
	
	public:
		void OnUpdate(TimeStep ts);

	private:
		void RenderPass();
		void UpdateEntitiesScript(TimeStep ts);

	private:
		// TODO : This has to be a weak ref
		Blackbird::Ref<Blackbird::Renderer2D> m_Renderer2D;
		
		LECS::Registry m_Registry;
		Entity m_PrimaryCameraEntity;

		std::uint32_t m_ViewportWidth = 0;
		std::uint32_t m_ViewportHeight = 0;
	};

}

#include "Entity.inl"
