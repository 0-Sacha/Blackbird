#include "OpenGLVertexArray.h"

#include "Blackbird/Engine/Asset/VertexBufferLayout.h"

#include "glad/glad.h"

static uint32_t FormShaderDataTypeToOpenGL(Blackbird::ShaderData::Type type)
{
	switch (type)
	{
		case Blackbird::ShaderData::Type::Bool:		return GL_BOOL;
		case Blackbird::ShaderData::Type::Int:		return GL_INT;
		case Blackbird::ShaderData::Type::Int2:		return GL_INT;
		case Blackbird::ShaderData::Type::Int3:		return GL_INT;
		case Blackbird::ShaderData::Type::Int4:		return GL_INT;
		case Blackbird::ShaderData::Type::Float:	return GL_FLOAT;
		case Blackbird::ShaderData::Type::Float2:	return GL_FLOAT;
		case Blackbird::ShaderData::Type::Float3:	return GL_FLOAT;
		case Blackbird::ShaderData::Type::Float4:	return GL_FLOAT;
		case Blackbird::ShaderData::Type::Mat3:		return GL_FLOAT;
		case Blackbird::ShaderData::Type::Mat4:		return GL_FLOAT;
	}

	BLACKBIRD_ASSERT(false, "Unkown ShaderDataType!");
	return 0;
}

namespace Blackbird::GraphicsPlatforms::OpenGL
{

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
		glBindVertexArray(m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Release() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();
		
		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for(const auto& element : layout.GetElements()) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				FormShaderDataTypeToOpenGL(element.ShaderDataType),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				reinterpret_cast<const void*>(element.Offset));
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}
