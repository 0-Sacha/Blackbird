
#include "GLFWWindow.h"

#include "Blackbird/EngineDetail/Event/ApplicationEvent.h"
#include "Blackbird/EngineDetail/Event/KeyboardEvent.h"
#include "Blackbird/EngineDetail/Event/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace Blackbird::WindowPlatforms::GLFW
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		BLACKBIRD_FATAL("GLFW Error ({0}): {1}", error, description);
	}

	static void GLFWWindowSizeCallback(GLFWwindow* window, int width, int height) {
		GLFWWindow::WindowData& data = *(GLFWWindow::WindowData*)glfwGetWindowUserPointer(window);
		data.Width = width;
		data.Height = height;

		WindowResizeEvent event(width, height);
		data.EventCallback(event);
	}

	static void GLFWWindowCloseCallback(GLFWwindow* window) {
		GLFWWindow::WindowData& data = *(GLFWWindow::WindowData*)glfwGetWindowUserPointer(window);

		WindowCloseEvent event;
		data.EventCallback(event);
	}

	static void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		GLFWWindow::WindowData& data = *(GLFWWindow::WindowData*)glfwGetWindowUserPointer(window);

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
		GLFWWindow::WindowData& data = *(GLFWWindow::WindowData*)glfwGetWindowUserPointer(window);

		KeyTypedEvent event(keyCode);
		data.EventCallback(event);
	}

	static void GLFWMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		GLFWWindow::WindowData& data = *(GLFWWindow::WindowData*)glfwGetWindowUserPointer(window);

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
		GLFWWindow::WindowData& data = *(GLFWWindow::WindowData*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		data.EventCallback(event);
	}

	static void GLFWCursorPosCallback(GLFWwindow* window, double xPos, double yPos) {
		GLFWWindow::WindowData& data = *(GLFWWindow::WindowData*)glfwGetWindowUserPointer(window);

		MouseMouvedEvent event((float)xPos, (float)yPos);
		data.EventCallback(event);
	}

	GLFWWindow::GLFWWindow(const WindowProps& props, PlatformAPI& platformAPI)
		: m_RendererContext(nullptr)
		, m_Window(nullptr)
		, m_Data()
	{
		Init(props, platformAPI);
	}

	GLFWWindow::~GLFWWindow()
	{
		Shutdown();
	}

	void GLFWWindow::Init(const WindowProps& props, PlatformAPI& platformAPI)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		BLACKBIRD_INFO("Creating {0}  {{1}, {2}}", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			BLACKBIRD_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		BLACKBIRD_DEBUG("GLFW Window created");

		m_RendererContext = platformAPI.GraphicsPlatform().GetNewGLFWRendererContext(m_Window);
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
		BLACKBIRD_DEBUG("GLFW Event Binded");
	}

	void GLFWWindow::Shutdown()
	{
		m_RendererContext->Destroy();
		// TODO : Need this ???
		// glfwDestroyWindow(m_Window);
		glfwTerminate();
		BLACKBIRD_DEBUG("GLFW Window: Destroyed");
	}

	void GLFWWindow::OnUpdate()
	{
		glfwPollEvents();
		m_RendererContext->SwapBuffer();
	}

	void GLFWWindow::SetVSync(bool enable)
	{
		if (enable)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_Data.VSync = enable;
	}

	bool GLFWWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
