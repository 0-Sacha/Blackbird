#pragma once

#include "Blackbird/Core/Core.h"
#include "Blackbird/Engine/Camera/OrthographicCamera.h"

namespace Blackbird
{
    class Renderer2D;

	class IDesigner2DManager
	{
	public:
		IDesigner2DManager(Renderer2D& renderer2D)
			: m_Renderer2D(renderer2D)
		{}

	public:
		virtual void Init() = 0;
		virtual void Release() = 0;

	public:
		virtual void BeginScene(const OrthographicCamera& camera) = 0;
		virtual void Flush() = 0;
		virtual void EndScene() = 0;

	public:
		Renderer2D& GetRenderer2D() { return m_Renderer2D; }

	protected:
		Renderer2D& m_Renderer2D;
	};

    class IDesigner2D
    {
	public:
		IDesigner2D(IDesigner2DManager* defaultManager = nullptr)
            : m_DefaultManager(defaultManager)
        {}

    public:
		virtual void Draw(IDesigner2DManager& renderer) = 0;
		virtual void DrawInstant(IDesigner2DManager& renderer) = 0;

        void DefaultDraw()
        {
            if (m_DefaultManager != nullptr)
                return Draw(*m_DefaultManager);
            BLACKBIRD_WARN("Use of DefaultDraw on a Designer2D but there is no DefaultManager set");
        }

		void DefaultDrawInstant()
		{
			if (m_DefaultManager != nullptr)
				return DrawInstant(*m_DefaultManager);
			BLACKBIRD_WARN("Use of DefaultDraw on a Designer2D but there is no DefaultManager set");
		}

	private:
		IDesigner2DManager* m_DefaultManager = nullptr;
    };

	template <typename DesignerType>
	class Designer2DDrawOnDestroy
	{
	public:
		Designer2DDrawOnDestroy(const DesignerType& designer)
			: m_Designer(designer)
		{}

		~Designer2DDrawOnDestroy() { m_Designer.DefaultDraw(); }

	public:
		DesignerType* operator->()
		{
			return &m_Designer;
		}

	private:
		DesignerType m_Designer;
	};

}
