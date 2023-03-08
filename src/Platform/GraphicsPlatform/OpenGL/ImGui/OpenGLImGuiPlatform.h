#pragma once

#include "Blackbird/ImGui/ImGuiLayer.h"

#include "imgui.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{
	class OpenGLImGuiPlatform : public ImGuiLayer::IImGuiGraphicsPlatform
	{
	public:
		OpenGLImGuiPlatform() = default;
		~OpenGLImGuiPlatform() = default;

	public:
		void InitImpl() override;
		void ShutdownImpl() override;
		void NewFrameImpl() override;
		void OnRenderImpl() override;
	};
}
