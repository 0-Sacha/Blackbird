#pragma once

#include "Blackbird/Core/Core.h"

namespace Blackbird
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual void Release(uint32_t slot = 0) const = 0;

		virtual std::uint32_t GetRendererID() const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
	};
}
