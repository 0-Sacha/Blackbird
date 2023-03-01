#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Camera/OrthographicCamera.h"

namespace Blackbird
{
    class Renderer2D;

    class IDesigner2D
    {
	public:
		IDesigner2D(Renderer2D* defaultRenderer = nullptr)
            : m_DefaultRenderer(defaultRenderer)
        {}

    public:
		virtual void Draw(Renderer2D& renderer) = 0;
        void DefaultDraw()
        {
            if (m_DefaultRenderer != nullptr)
                return Draw(*m_DefaultRenderer);
            BLACKBIRD_WARN("Use of DefaultDraw on a Designer2D but there is no default renderer set");
        }

	private:
		Renderer2D* m_DefaultRenderer = nullptr;
    };

    class IDesigner2DManager
    {
    public:
        virtual void Init(Renderer2D& m_Renderer2D) = 0;
        virtual void Release() = 0;

	public:
		virtual void BeginScene(const OrthographicCamera& camera) = 0;
		virtual void EndScene() = 0;
    };
}
