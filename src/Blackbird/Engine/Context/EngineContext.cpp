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
        m_PlatformAPI->SetWindowPlatform(std::make_unique<WindowPlatforms::GLFW::GLFWPlatform>());
        m_PlatformAPI->SetGraphicsPlatform(std::make_unique<GraphicsPlatforms::OpenGL::OpenGLPlatform>());
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
        BLKBID_DEBUG("Shutdown Renderer...");
		m_Renderer->Shutdown();
		BLACKBIRD_ASSERT(m_Renderer.use_count() == 1, "Renderer is still use");
        m_Renderer = nullptr;

		BLKBID_DEBUG("Shutdown Renderer2D...");
		m_Renderer2D->Shutdown();
		BLACKBIRD_ASSERT(m_Renderer2D.use_count() == 1, "Renderer2D is still use");
        m_Renderer2D = nullptr;

		BLKBID_DEBUG("Shutdown EngineAPI...");
        m_EngineAPI->Shutdown();
		BLACKBIRD_ASSERT(m_EngineAPI.use_count() == 1, "EngineAPI is still use");
		m_EngineAPI = nullptr;

		BLKBID_DEBUG("Shutdown PlatformAPI...");
		// m_PlatformAPI->Shutdown();
		BLACKBIRD_ASSERT(m_PlatformAPI.use_count() == 1, "PlatformAPI is still use");
		m_PlatformAPI = nullptr;
    }
}
