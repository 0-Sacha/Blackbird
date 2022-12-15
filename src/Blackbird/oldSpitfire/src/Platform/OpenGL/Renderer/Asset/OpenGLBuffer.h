
#pragma once

#include "Spitfire/Core/Core.h"
#include "Spitfire/Renderer/Asset/RendererBuffer.h"

namespace Spitfire {


	/////---------- VertexBuffer ----------/////

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer() override;

	public:
		void Bind() const override;
		void Unbind() const override;

		void SetLayout(const BufferLayout& layout) override { m_Layout = layout; };
		const BufferLayout& GetLayout() const override { return m_Layout; };

	private:
		RendererID m_RendererID;
		BufferLayout m_Layout;
	};



	/////---------- VertexBuffer ----------/////

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer() override;

	public:
		void Bind() const override;
		void Unbind() const override;

		uint32_t GetCount() override { return m_Count; };

	private:
		RendererID m_RendererID;
		uint32_t m_Count;
	};
}