#pragma once

#include "Blackbird/Core/Core.h"

typedef unsigned int GLenum;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef char GLchar;

namespace Blackbird::GraphicsPlatform::OpenGL
{
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
