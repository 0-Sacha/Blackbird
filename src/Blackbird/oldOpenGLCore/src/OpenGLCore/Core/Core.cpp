
#include "OGLCpch.h"

#include "Core.h"

CPPTools::LogSystem& OGLC::Core::Logger()
{
	static CPPTools::LogSystem instance("OpenGlCore");
	return instance;
}
