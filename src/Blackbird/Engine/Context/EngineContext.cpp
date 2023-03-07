#include "EngineContext.h"

#include "Platform/WindowPlatform/GLFW/GLFWPlatform.h"
#include "Platform/GraphicsPlatform/OpenGL/OpenGLPlatform.h"

namespace Blackbird
{
    void EngineContext::Clear()
    {
        m_PlatformAPI = nullptr;
        m_EngineAPI = nullptr;
        m_Renderer = nullptr;
        m_Renderer2D = nullptr;
    }

	void EngineContext::Set(EngineContext& context)
    {
        m_PlatformAPI = context.m_PlatformAPI;
        m_EngineAPI = context.m_EngineAPI;
        m_Renderer = context.m_Renderer;
        m_Renderer2D = context.m_Renderer2D;
    }

    void EngineContext::OnWindowResize(std::uint32_t width, std::uint32_t height)
	{
		m_EngineAPI->RendererCommand().SetViewport(0, 0, width, height);
	}



    void MasterEngineContext::InitPlatformAPI()
    {
        m_PlatformAPI = std::make_shared<PlatformAPI>();
        m_PlatformAPI->SetWindowPlatform(std::make_unique<WindowPlatform::GLFW::GLFWPlatform>());
        m_PlatformAPI->SetGraphicsPlatform(std::make_unique<GraphicsPlatform::OpenGL::OpenGLPlatform>());
    }

    void MasterEngineContext::InitEngineAPI(Ref<Window>& window)
    {
        m_EngineAPI = std::make_shared<EngineAPI>();
		m_PlatformAPI->WindowPlatform().InitEngineAPI(*m_EngineAPI, window);
        m_PlatformAPI->GraphicsPlatform().InitEngineAPI(*m_EngineAPI);
        m_EngineAPI->Init();
    }

    void MasterEngineContext::CreateRenderer()
    {
        m_Renderer = std::make_shared<Renderer>();
        m_Renderer->Init(m_EngineAPI);
    }

    void MasterEngineContext::CreateRenderer2D()
    {
		m_Renderer2D = std::make_shared<Renderer2D>();
        m_Renderer2D->Init(m_EngineAPI);
    }

    void MasterEngineContext::Destroy()
    {
		m_Renderer->Shutdown();
        m_Renderer = nullptr;

		m_Renderer2D->Shutdown();
        m_Renderer2D = nullptr;

        m_EngineAPI->Shutdown();
        m_EngineAPI = nullptr;

        // m_PlatformAPI->Shutdown();
        m_PlatformAPI = nullptr;
    }
}
