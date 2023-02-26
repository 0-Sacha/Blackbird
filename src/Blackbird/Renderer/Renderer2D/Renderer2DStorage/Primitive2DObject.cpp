#include "Primitive2DObject.h"

namespace Blackbird::Renderer2DUtils::Primitive
{

	void Primitive2DQuad::Init()
	{
		QuadVA = VertexArray::Create();

		float squareVertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,	1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f,	1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f,	0.0f, 1.0f
		};

		std::shared_ptr<VertexBuffer> squareVertexBuffer = VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		BufferLayout squareLayout = {
			{ ShaderData::Type::Float3, "a_Position" },
			{ ShaderData::Type::Float2, "a_TexCoord" }
		};
		squareVertexBuffer->SetLayout(squareLayout);
		QuadVA->AddVertexBuffer(squareVertexBuffer);

		uint32_t squareIndices[] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<IndexBuffer> squareIndexBuffer = IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		QuadVA->SetIndexBuffer(squareIndexBuffer);
	}

	void Primitive2DQuad::Release()
	{

	}

}
