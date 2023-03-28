#pragma once

#include "Blackbird/Core/Core.h"

#include "glm/glm.hpp"

namespace Blackbird
{

	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual void Release(uint32_t slot = 0) const = 0;
	
	public:
		virtual std::uint32_t GetWidth() const = 0;
		virtual std::uint32_t GetHeight() const = 0;
		float GetRatio() const { return (float)GetHeight() / GetWidth(); }

	public:
		virtual std::uint32_t GetTextureID() const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		~Texture2D() override = default;

	public:
		virtual glm::vec2 GetTexCoordsMin() const { return { 0.0f, 0.0f }; }
		virtual glm::vec2 GetTexCoordsMax() const { return { 1.0f, 1.0f }; }
	};

}
