#pragma once

#include "Blackbird/Core/Core.h"

namespace Blackbird
{
	class Statistics2D
	{
	public:
		std::uint32_t DrawCall = 0;

	public:
		virtual void Reset() { DrawCall = 0; }

	public:
		virtual std::uint32_t GetVerticiesCount() = 0;
		virtual std::uint32_t GetIndiciesCount() = 0;
	};
}
