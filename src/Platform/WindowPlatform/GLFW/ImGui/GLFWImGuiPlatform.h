#pragma once

#include "Blackbird/ImGui/ImGuiLayer.h"

#include "imgui.h"

namespace Blackbird::WindowPlatform::GLFW
{
	class GLFWImGuiPlatform : public ImGuiLayer::IImGuiWindowPlatform
	{
	public:
		GLFWImGuiPlatform() = default;
		~GLFWImGuiPlatform() = default;

	public:
		void InitImpl(Window& window) override;
		void ShutdownImpl() override;
		void NewFrameImpl() override;
		void ViewportPassImpl() override;
	};
}
