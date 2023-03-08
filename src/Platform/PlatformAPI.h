#pragma once

#include "GraphicsPlatform/IGraphicsPlatform.h"
#include "WindowPlatform/IWindowPlatform.h"

#include <memory>

namespace Blackbird
{
	class PlatformAPI
	{
	public:
		WindowPlatforms::IWindowPlatform& WindowPlatform() 		{ return *m_WindowPlatform; }
		GraphicsPlatforms::IGraphicsPlatform& GraphicsPlatform() { return *m_GraphicsPlatform; }

	public:
		Ref<Window> CreateWindow(const WindowProps& props)
		{
			return m_WindowPlatform->CreateWindow(props, *this);
		}

	public:
		void SetWindowPlatform(std::unique_ptr<WindowPlatforms::IWindowPlatform>&& windowPlatform) 			{ m_WindowPlatform = std::move(windowPlatform); }
		void SetGraphicsPlatform(std::unique_ptr<GraphicsPlatforms::IGraphicsPlatform>&& graphicsPlatform) 	{ m_GraphicsPlatform = std::move(graphicsPlatform); }

	private:
		Scope<WindowPlatforms::IWindowPlatform> m_WindowPlatform;
		Scope<GraphicsPlatforms::IGraphicsPlatform> m_GraphicsPlatform;
	};
}
