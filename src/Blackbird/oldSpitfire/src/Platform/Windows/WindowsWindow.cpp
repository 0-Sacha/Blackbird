
#include "Spitfirepch.h"
#include "WindowsWindow.h"

#include "Spitfire/Event/ApplicationEvent.h"
#include "Spitfire/Event/KeyboardEvent.h"
#include "Spitfire/Event/MouseEvent.h"

#include "Platform/OpenGL/Renderer/Context/OpenGLContext.h"

#include <GLFW/glfw3.h>

namespace Spitfire {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		SPITFIRE_FATAL("GLFW Error ({0}): {1}", error, description);
	}

	static void GLFWWindowSizeCallback(GLFWwindow* window, int width, int height) {
		WindowsWindow::WindowData& data = *(WindowsWindow::WindowData*)glfwGetWindowUserPointer(window);
		data.Width = width;
		data.Height = height;

		WindowResizeEvent event(width, height);
		data.EventCallback(event);
	}

	static void GLFWWindowCloseCallback(GLFWwindow* window) {
		WindowsWindow::WindowData& data = *(WindowsWindow::WindowData*)glfwGetWindowUserPointer(window);

		WindowCloseEvent event;
		data.EventCallback(event);
	}

	static void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		WindowsWindow::WindowData& data = *(WindowsWindow::WindowData*)glfwGetWindowUserPointer(window);

		switch (action)
		{
		case GLFW_PRESS:
		{
			KeyPressedEvent event(key, 0);
			data.EventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyReleasedEvent event(key);
			data.EventCallback(event);
			break;
		}
		case GLFW_REPEAT:
		{
			KeyPressedEvent event(key, 1);
			data.EventCallback(event);
			break;
		}
		}
	}

	static void GLFWCharCallback(GLFWwindow* window, uint32_t keyCode) {
		WindowsWindow::WindowData& data = *(WindowsWindow::WindowData*)glfwGetWindowUserPointer(window);

		KeyTypedEvent event(keyCode);
		data.EventCallback(event);
	}

	static void GLFWMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		WindowsWindow::WindowData& data = *(WindowsWindow::WindowData*)glfwGetWindowUserPointer(window);

		switch (action)
		{
		case GLFW_PRESS:
		{
			MouseButtonPressedEvent event(button);
			data.EventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseButtonReleasedEvent event(button);
			data.EventCallback(event);
			break;
		}
		}
	}

	static void GLFWScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
		WindowsWindow::WindowData& data = *(WindowsWindow::WindowData*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		data.EventCallback(event);
	}

	static void GLFWCursorPosCallback(GLFWwindow* window, double xPos, double yPos) {
		WindowsWindow::WindowData& data = *(WindowsWindow::WindowData*)glfwGetWindowUserPointer(window);

		MouseMouvedEvent event((float)xPos, (float)yPos);
		data.EventCallback(event);
	}




	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		SPITFIRE_INFO("Creating Windows-window {0}  #{{1}, {2}}", props.Title, props.Width, props.Height);


		if (!s_GLFWInitialized) {
			int success = glfwInit();
			SPITFIRE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);

		m_RendererContext = new OpenGLContext(m_Window);
		m_RendererContext->Init();
		m_RendererContext->DisplayInfo();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, GLFWWindowSizeCallback);

		glfwSetWindowCloseCallback(m_Window, GLFWWindowCloseCallback);

		glfwSetKeyCallback(m_Window, GLFWKeyCallback);

		glfwSetCharCallback(m_Window, GLFWCharCallback);

		glfwSetMouseButtonCallback(m_Window, GLFWMouseButtonCallback);

		glfwSetScrollCallback(m_Window, GLFWScrollCallback);

		glfwSetCursorPosCallback(m_Window, GLFWCursorPosCallback);
	}

	void WindowsWindow::Shutdown()
	{
		m_RendererContext->Destroy();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		m_RendererContext->SwapBuffer();
	}

	void WindowsWindow::SetVSync(bool enable)
	{
		if (enable)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_Data.VSync = enable;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}