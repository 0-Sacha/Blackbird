#pragma once

#include "GraphicsPlatform/GraphicsPlatform.h"
#include "WindowPlatform/WindowPlatform.h"

#include <memory>

namespace Blackbird
{
	class PlatformAPI
	{
	public:
		WindowPlatform::IWindowPlatform& WindowPlatform() 		{ return *m_WindowPlatform; }
		GraphicsPlatform::IGraphicsPlatform& GraphicsPlatform() { return *m_GraphicsPlatform; }

	public:
		Scope<Window> CreateWindow(const WindowProps& props)
		{
			return m_WindowPlatform->CreateWindow(props, *this);
		}

	public:
		void SetWindowPlatform(std::unique_ptr<WindowPlatform::IWindowPlatform>&& windowPlatform) 			{ m_WindowPlatform = std::move(windowPlatform); }
		void SetGraphicsPlatform(std::unique_ptr<GraphicsPlatform::IGraphicsPlatform>&& graphicsPlatform) 	{ m_GraphicsPlatform = std::move(graphicsPlatform); }

	private:
		std::unique_ptr<WindowPlatform::IWindowPlatform> m_WindowPlatform;
		std::unique_ptr<GraphicsPlatform::IGraphicsPlatform> m_GraphicsPlatform;
	};
}
