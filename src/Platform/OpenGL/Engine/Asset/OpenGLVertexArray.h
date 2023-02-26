#pragma once

#include "Platform/OpenGL/OpenGLCore.h"
#include "Blackbird/Engine/Asset/VertexArray.h"


namespace Blackbird::Platform::OpenGL
{

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray() override;

	public:
		void Bind() const override;
		void Release() const override;

		void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

		const std::vector<Ref<VertexBuffer>> GetVertexBuffers() const override;
		const Ref<Blackbird::IndexBuffer> GetIndexBuffer() const override;

	private:
		RendererID m_RendererID;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};

}
