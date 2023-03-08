#include "OpenGLImGuiPlatform.h"

#include "glad/glad.h"
#include "backends/imgui_impl_opengl3.h"

namespace Blackbird::GraphicsPlatforms::OpenGL
{

	void OpenGLImGuiPlatform::InitImpl()
	{
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void OpenGLImGuiPlatform::ShutdownImpl()
	{
		ImGui_ImplOpenGL3_Shutdown();
	}

	void OpenGLImGuiPlatform::NewFrameImpl()
	{
		ImGui_ImplOpenGL3_NewFrame();
	}

	void OpenGLImGuiPlatform::OnRenderImpl()
	{
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

}
