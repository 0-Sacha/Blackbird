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
		glm::vec3 Translation{ 0.0f, 0.0f, 0.0f };
		glm::vec3 Rotation{ 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale{ 1.0f, 1.0f, 1.0f };

	public:
		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3& translation, const glm::vec3& rotation, const glm::vec3& scale)
			: Translation(translation)
			, Rotation(rotation)
			, Scale(scale)
		{}
		
	public:
		glm::mat4 GetTransform() const
		{
			glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), Rotation.x, { 1, 0, 0 })
				* glm::rotate(glm::mat4(1.0f), Rotation.y, { 0, 1, 0 })
				* glm::rotate(glm::mat4(1.0f), Rotation.z, { 0, 0, 1 });

			return glm::translate(glm::mat4(1.0f), Translation)
				* rotation
				* glm::scale(glm::mat4(1.0f), Scale);
		}

		operator glm::mat4 () const { return GetTransform(); }
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
