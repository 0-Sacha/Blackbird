
#include "OGLCpch.h"
#include "OpenGlDebug.h"

namespace OGLC::Debug {

	static OpenGlDebugLevel s_OpenGlDebugLevel = OpenGlDebugLevel::HighAssert;

	void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
	{
		switch(severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:
			if(s_OpenGlDebugLevel > OpenGlDebugLevel::None) {
				OGLC_FATAL("[OpenGL Debug HIGH] {}", message);
				if (s_OpenGlDebugLevel == OpenGlDebugLevel::HighAssert)
					OGLC_ASSERT(false, "GL_DEBUG_SEVERITY_HIGH");
			}
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			if (s_OpenGlDebugLevel >= OpenGlDebugLevel::Medium)
				OGLC_ERROR("[OpenGL Debug MEDIUM] {}", message);
			break;
		case GL_DEBUG_SEVERITY_LOW:
			if (s_OpenGlDebugLevel >= OpenGlDebugLevel::Low)
				OGLC_WARN("[OpenGL Debug LOW] {}", message);
			break;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			if (s_OpenGlDebugLevel >= OpenGlDebugLevel::Notification)
				OGLC_TRACE("[OpenGL Debug NOTIFICATION] {}", message);
			break;
		}
	}

	void SetOpenGlDebugLevel(OpenGlDebugLevel level)
	{
		s_OpenGlDebugLevel = level;
	}

	void EnableOpenGlDebugging()
	{
		glDebugMessageCallback(OpenGLLogMessage, nullptr);
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	}
}