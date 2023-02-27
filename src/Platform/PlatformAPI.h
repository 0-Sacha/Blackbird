#pragma once

#include "GraphicsPlatform/GraphicsPlatform.h"
#include "WindowPlatform/WindowPlatform.h"

#include <memory>

namespace Blackbird
{
	class PlatformAPI
	{
	public:
		static PlatformAPI& GetInstance();

	public:
		WindowPlatform::IWindowPlatform& GetWindowPlatform() 		{ return *m_WindowPlatform; }
		GraphicsPlatform::IGraphicsPlatform& GetGraphicsPlatform() 	{ return *m_GraphicsPlatform; }

	public:
		void SetWindowPlatform(std::unique_ptr<WindowPlatform::IWindowPlatform>&& windowPlatform) 			{ m_WindowPlatform = std::move(windowPlatform); }
		void SetGraphicsPlatform(std::unique_ptr<GraphicsPlatform::IGraphicsPlatform>&& graphicsPlatform) 	{ m_GraphicsPlatform = std::move(graphicsPlatform); }

	private:
		std::unique_ptr<WindowPlatform::IWindowPlatform> m_WindowPlatform;
		std::unique_ptr<GraphicsPlatform::IGraphicsPlatform> m_GraphicsPlatform;
	};
}
