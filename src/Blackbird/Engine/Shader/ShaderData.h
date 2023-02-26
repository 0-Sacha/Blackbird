#pragma once

#include "Blackbird/Core/Core.h"

namespace Blackbird
{
	class ShaderData
	{
	public:
		enum class Type
		{
			None = 0,
			Bool,
			Int, Int2, Int3, Int4,
			Float, Float2, Float3, Float4,
			Mat3, Mat4
		};

	public:
		static uint32_t GetSizeOf(ShaderData::Type type);
		static uint32_t GetComponentCountOf(ShaderData::Type type);
	};
}
