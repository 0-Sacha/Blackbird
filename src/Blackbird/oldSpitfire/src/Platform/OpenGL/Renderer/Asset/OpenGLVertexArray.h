#pragma once

#include "Spitfire/Core/Core.h"
#include "Spitfire/Renderer/Asset/VertexArray.h"


namespace Spitfire {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray() override;

	public:
		void Bind() override;
		void Unbind() override;

		void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

		const std::vector<Ref<VertexBuffer>> GetVertexBuffers() const override;
		const Ref<Spitfire::IndexBuffer> GetIndexBuffer() const override;

	private:
		RendererID m_RendererID;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};

}