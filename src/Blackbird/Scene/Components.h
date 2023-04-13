#pragma once

#include <glm/glm.hpp>
#include <string>

#include "SceneCamera.h"
#include "NativeScript.h"

namespace Blackbird
{

	struct TransformComponent
	{
	public:
		glm::mat4 Transform{ 1.0f };

	public:
		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		
	public:
		TransformComponent(const glm::mat4& transform)
			: Transform(transform)
		{}

	public:
		operator glm::mat4& () { return Transform; }
		operator const glm::mat4& () const { return Transform; }
	};

	struct TagComponent
	{
	public:
		std::string Tag;

	public:
		TagComponent() = default;
		TagComponent(const TagComponent&) = default;

	public:
		TagComponent(const std::string& tag)
			: Tag(tag)
		{}
	};

	struct SpritRendererComponent
	{
	public:
		glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };

	public:
		SpritRendererComponent() = default;
		SpritRendererComponent(const SpritRendererComponent&) = default;

	public:
		SpritRendererComponent(const glm::vec4& color)
			: Color(color)
		{}
	};

	struct SceneCameraComponent
	{
	public:
		SceneCamera Camera;
		bool ResizeAspectRatioOnViewport = false;

	public:
		SceneCameraComponent() = default;
		SceneCameraComponent(const SceneCameraComponent&) = default;
		SceneCameraComponent(float size, float nearClip, float farClip)
			: Camera(size, nearClip, farClip)
		{}

	};

	struct NativeScriptComponent
	{
	public:
		Scope<NativeScript> Script = nullptr;
		bool Enable = true;

	public:
		template <typename T, typename... Args>
		void Bind(Args&&... args)
		{
			Script = std::make_unique<T>(std::forward<Args>(args)...);
			Script->OnBind();
		}

		void Release()
		{
			Script->OnRelease();
			Script.reset(nullptr);
		}

	public:
		NativeScriptComponent() = default;
		NativeScriptComponent(const NativeScriptComponent&) = default;
	};
}
