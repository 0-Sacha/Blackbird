#pragma once

#include "Blackbird/Core/Window.h"
#include "Blackbird/Renderer/Context/RendererContext.h"

struct GLFWwindow;

namespace Blackbird {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; }
		inline uint32_t GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enable) override;
		bool IsVSync() const override;

		inline void* GetNativeWindow() const override { return m_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	public:
		struct WindowData
		{
			std::string Title;
			uint32_t Width;
			uint32_t Height;
			bool VSync;
			Window::EventCallbackFn EventCallback;
		};

	private:
		GLFWwindow* m_Window;
		RendererContext* m_RendererContext;
		WindowData m_Data;
	};

}