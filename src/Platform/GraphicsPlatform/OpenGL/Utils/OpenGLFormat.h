#pragma once

#include <glad/glad.h>

namespace EngineCore::FMT
{
	template<typename FormatContext>
	struct FormatterType<GLubyte*, FormatContext>
	{
		static void Format(const GLubyte* t, FormatContext& context) {
			FormatterType<char*, FormatContext>::Format(reinterpret_cast<const char*>(t), context);
		}
	};
}
