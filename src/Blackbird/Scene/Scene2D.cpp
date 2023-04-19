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
		Entity entity = { this, m_Registry.CreateEntityId() };
		entity.Add<TransformComponent>();
		TagComponent& tag = entity.Add<TagComponent>();
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

		m_Renderer2D->BeginScene(m_PrimaryCameraEntity.Get<SceneCameraComponent>().Camera, m_PrimaryCameraEntity.Get<TransformComponent>().GetTransform());

		m_Registry.ForEachComponents<TransformComponent, SpritRendererComponent>([&](const TransformComponent& transform, const SpritRendererComponent& sprite){
			m_Renderer2D->DrawQuadT()->SetTranform(transform).SetColor(sprite.Color);
		});

		m_Renderer2D->EndScene();
	}

	void Scene2D::UpdateEntitiesScript(TimeStep ts)
	{
		m_Registry.ForEachUniqueComponent<NativeScriptComponent>([ts](NativeScriptComponent& nativeScriptComponent) {
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

		m_Registry.ForEachUniqueComponent<SceneCameraComponent>([&](SceneCameraComponent& cameraComponent){
			if (cameraComponent.ResizeAspectRatioOnViewport)
			{
				cameraComponent.Camera.SetViewportSize(width, height);
			}
		});
	}

}
