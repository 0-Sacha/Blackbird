#pragma once

#include "OGLCpch.h"

namespace CPPTools::Fmt {

	template<>
	struct FormatType<GLubyte*>
	{
		static void Write(const GLubyte* t, Formater& formater, const FormatData& data) {
			FormatType<char*>::Write((const char*)t, formater, data);
		}
	};

}