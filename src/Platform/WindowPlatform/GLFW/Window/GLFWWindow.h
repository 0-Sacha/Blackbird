#pragma once

#include "Blackbird/EngineDetail/Window.h"
#include "Blackbird/Engine/Context/IRendererContext.h"

#include "Platform/PlatformAPI.h"

struct GLFWwindow;

namespace Blackbird::WindowPlatform::GLFW
{
	class GLFWWindow : public Window
	{
	public:
		GLFWWindow(const WindowProps& props, PlatformAPI& platformAPI);
		~GLFWWindow() override;

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; }
		inline uint32_t GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enable) override;
		bool IsVSync() const override;

		inline void* GetNativeWindow() const override { return m_Window; }

	private:
		virtual void Init(const WindowProps& props, PlatformAPI& platformAPI);
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
		Scope<IRendererContext> m_RendererContext;
		GLFWwindow* m_Window;
		WindowData m_Data;
	};
}
