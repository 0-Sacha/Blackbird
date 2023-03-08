#include "OpenGLShader.h"

#include "glad/glad.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Release() const
	{
		glUseProgram(0);
	}

}
