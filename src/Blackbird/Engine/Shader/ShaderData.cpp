#include "ShaderData.h"

namespace Blackbird
{
	uint32_t ShaderData::GetSizeOf(ShaderData::Type type)
	{
		switch (type)
		{
			case ShaderData::Type::Bool:	return 1;
			case ShaderData::Type::Int:		return 4;
			case ShaderData::Type::Int2:	return 4 * 2;
			case ShaderData::Type::Int3:	return 4 * 3;
			case ShaderData::Type::Int4:	return 4 * 4;
			case ShaderData::Type::Float:	return 4;
			case ShaderData::Type::Float2:	return 4 * 2;
			case ShaderData::Type::Float3:	return 4 * 3;
			case ShaderData::Type::Float4:	return 4 * 4;
			case ShaderData::Type::Mat3:	return 4 * 3 * 3;
			case ShaderData::Type::Mat4:	return 4 * 4 * 4;
		}
		BLACKBIRD_ASSERT(false, "Unkown ShaderDataType!");
		return 0;
	}

	uint32_t ShaderData::GetComponentCountOf(ShaderData::Type type)
	{
		switch (type)
		{
			case ShaderData::Type::Bool:	return 1;
			case ShaderData::Type::Int:		return 1;
			case ShaderData::Type::Int2:	return 2;
			case ShaderData::Type::Int3:	return 3;
			case ShaderData::Type::Int4:	return 4;
			case ShaderData::Type::Float:	return 1;
			case ShaderData::Type::Float2:	return 2;
			case ShaderData::Type::Float3:	return 3;
			case ShaderData::Type::Float4:	return 4;
			case ShaderData::Type::Mat3:	return 3 * 3;
			case ShaderData::Type::Mat4:	return 4 * 4;
		}
		BLACKBIRD_ASSERT(false, "Unkown ShaderDataType!");
		return 0;
	}
}
