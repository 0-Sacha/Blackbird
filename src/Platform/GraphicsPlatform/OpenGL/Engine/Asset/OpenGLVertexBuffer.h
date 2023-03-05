
#pragma once

#include "Platform/GraphicsPlatform/OpenGL/OpenGLCore.h"
#include "Blackbird/Engine/Asset/VertexBuffer.h"

namespace Blackbird::GraphicsPlatform::OpenGL
{

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size);
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer() override;

	public:
		void Bind() const override;
		void Release() const override;

		void SetLayout(const BufferLayout& layout) override { m_Layout = layout; };
		const BufferLayout& GetLayout() const override { return m_Layout; };

		void SetData(const void* data, std::uint32_t size) override;

	private:
		OpenGLRendererID m_RendererID;
		BufferLayout m_Layout;
	};


	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer() override;

	public:
		void Bind() const override;
		void Release() const override;

		uint32_t GetCount() override { return m_Count; };

	private:
		OpenGLRendererID m_RendererID;
		uint32_t m_Count;
	};
}
