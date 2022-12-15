#pragma once

#include <glad/glad.h>
#include "OpenGlCore/Core/Core.h"

namespace OGLC::Debug {

	enum class OpenGlDebugLevel
	{
		None,
		HighAssert,
		High,
		Medium,
		Low,
		Notification,
	};

	void EnableOpenGlDebugging();
	void SetOpenGlDebugLevel(OpenGlDebugLevel level);
	void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
}