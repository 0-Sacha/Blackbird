#pragma once

#include "Blackbirdpch.h"

#include <glad/glad.h>

namespace EngineCore::FMT {

	template<typename FormatContext>
	struct FormatType<GLubyte*, FormatContext>
	{
		static void Write(const GLubyte* t, FormatContext& context) {
			FormatType<char*, FormatContext>::Write(reinterpret_cast<const char*>(t), context);
		}
	};

}