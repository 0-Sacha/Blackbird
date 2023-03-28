#include "Scene2D.h"

#include "Entity.h"
#include "Components.h"

namespace Blackbird
{

	Scene2D::Scene2D(Blackbird::Ref<Blackbird::Renderer2D>& renderer)
		: m_Renderer2D(renderer)
	{}

	Scene2D::~Scene2D()
	{}

	Entity Scene2D::CreateEntity(const std::string& name)
	{
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		TagComponent& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}

	void Scene2D::OnUpdate(TimeStep ts)
	{
		UpdateEntitiesScript(ts);

		RenderPass();
	}

	void Scene2D::RenderPass()
	{
		if (m_PrimaryCameraEntity == false)
			return;

		m_Renderer2D->BeginScene(m_PrimaryCameraEntity.GetComponent<SceneCameraComponent>().Camera, m_PrimaryCameraEntity.GetComponent<TransformComponent>().Transform);

		auto group = m_Registry.group<TransformComponent>(entt::get<SpritRendererComponent>);
		for (auto entity : group)
		{
			const auto& [transform, sprite] = group.get<TransformComponent, SpritRendererComponent>(entity);
			m_Renderer2D->DrawQuadT()->SetTranform(transform).SetColor(sprite.Color);
		}

		m_Renderer2D->EndScene();
	}

	void Scene2D::UpdateEntitiesScript(TimeStep ts)
	{
		m_Registry.view<NativeScriptComponent>().each([ts](entt::entity entity, NativeScriptComponent& nativeScriptComponent) {
			if (nativeScriptComponent.Enable)
				nativeScriptComponent.Script->OnUpdate(ts);
		});
	}

	void Scene2D::OnViewportResize(std::uint32_t width, std::uint32_t height)
	{
		if (m_ViewportWidth == width && m_ViewportHeight == height)
			return;

		m_ViewportWidth = width;
		m_ViewportHeight = height;

		auto view = m_Registry.view<SceneCameraComponent>();
		for (auto entity : view)
		{
			SceneCameraComponent& cameraComponent = view.get<SceneCameraComponent>(entity);
			if (cameraComponent.ResizeAspectRatioOnViewport)
			{
				cameraComponent.Camera.SetViewportSize(width, height);
			}
		}

	}

}
