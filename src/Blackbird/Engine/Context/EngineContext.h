#pragma once

#include "Blackbird/EngineAPI.h"
#include "Platform/PlatformAPI.h"
#include "Blackbird/Engine/Renderer/Renderer.h"
#include "Blackbird/Engine/Renderer2D/Renderer2D.h"

namespace Blackbird
{
	class EngineContext
	{
    public:
        void Clear();
		void Set(EngineContext& context);

    public:
        PlatformAPI& Platform()     { return *m_PlatformAPI; }
        EngineAPI& Engine()         { return *m_EngineAPI; }
        Renderer& GetRenderer()     { return *m_Renderer; }
        Renderer2D& GetRenderer2D() { return *m_Renderer2D; }

        Ref<PlatformAPI>& PlatformRef()     { return m_PlatformAPI; }
        Ref<EngineAPI>& EngineRef()         { return m_EngineAPI; }
        Ref<Renderer>& GetRendererRef()     { return m_Renderer; }
        Ref<Renderer2D>& GetRenderer2DRef() { return m_Renderer2D; }

	public:
		IRendererCommand& RendererCommand() { return m_EngineAPI->RendererCommand(); }
		IAssetFactory& AssetFactory()       { return m_EngineAPI->AssetFactory(); }
		IShaderFactory& ShaderFactory()     { return m_EngineAPI->ShaderFactory(); }
		ITextureFactory& TextureFactory()   { return m_EngineAPI->TextureFactory(); }
		IInput& Input()                     { return m_EngineAPI->Input(); }

    public:
        void OnWindowResize(std::uint32_t width, std::uint32_t height);

    protected:
        Ref<PlatformAPI> m_PlatformAPI;
        Ref<EngineAPI> m_EngineAPI;
        Ref<Renderer> m_Renderer;
        Ref<Renderer2D> m_Renderer2D;
	};

    class MasterEngineContext : public EngineContext
	{
	public:
        void Create();
        void Destroy();

        void InitPlatformAPI();
        void InitEngineAPI();
        void CreateRenderer();
        void CreateRenderer2D();
    
    private:
        using EngineContext::Clear;
        using EngineContext::Set;
	};
}
