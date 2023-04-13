#include <glad/glad.h>
#include "OpenGlDebug.h"

namespace Blackbird::GraphicsPlatforms::OpenGL {

	static OpenGlDebugLevel s_OpenGlDebugLevel = OpenGlDebugLevel::HighAssert;

	void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
	{
		switch(severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:
			if(s_OpenGlDebugLevel > OpenGlDebugLevel::None)
			{
				BLKBID_FATAL("[OpenGL Debug HIGH] {}", message);
				if (s_OpenGlDebugLevel == OpenGlDebugLevel::HighAssert)
				{
					BLACKBIRD_ASSERT(false, "GL_DEBUG_SEVERITY_HIGH");
				}
			}
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			if (s_OpenGlDebugLevel >= OpenGlDebugLevel::Medium)
			{
				BLKBID_ERROR("[OpenGL Debug MEDIUM] {}", message);
			}
			break;
		case GL_DEBUG_SEVERITY_LOW:
			if (s_OpenGlDebugLevel >= OpenGlDebugLevel::Low)
			{
				BLKBID_WARN("[OpenGL Debug LOW] {}", message);
			}
			break;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			if (s_OpenGlDebugLevel >= OpenGlDebugLevel::Notification)
			{
				BLKBID_TRACE("[OpenGL Debug NOTIFICATION] {}", message);
			}
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






