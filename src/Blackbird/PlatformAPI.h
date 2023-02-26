#pragma once

#include "Blackbird/Core/Core.h"

#include "Engine/Renderer/RendererAPI.h"
#include "Engine/Asset/AssetFactoryImpl.h"
#include "Engine/Shader/ShaderFactoryImpl.h"
#include "Engine/Texture/TextureFactoryImpl.h"

#include "EngineDetail/Input/InputImpl.h"

namespace Blackbird
{
	class PlatformAPI
	{
	public:
		static PlatformAPI& GetInstance();

	public:
		RendererAPI& GetRendererAPI() 			{ return *m_RendererAPI; }
		AssetFactoryImpl& GetAssetFactory() 	{ return *m_AssetFactory; }
		ShaderFactoryImpl& GetShaderFactory() 	{ return *m_ShaderFactory; }
		TextureFactoryImpl& GetTextureFactory() { return *m_TextureFactory; }

		InputImpl& GetInput() 					{ return *m_Input; }

	public:
		void SetRendererAPI(std::unique_ptr<RendererAPI>&& rendererAPI) 				{ m_RendererAPI = std::move(rendererAPI); }
		void SetAssetFactory(std::unique_ptr<AssetFactoryImpl>&& assetFactory) 			{ m_AssetFactory = std::move(assetFactory); }
		void SetShaderFactory(std::unique_ptr<ShaderFactoryImpl>&& shaderFactory) 		{ m_ShaderFactory = std::move(shaderFactory); }
		void SetTextureFactory(std::unique_ptr<TextureFactoryImpl>&& textureFactory) 	{ m_TextureFactory = std::move(textureFactory); }

		void SetInput(std::unique_ptr<InputImpl>&& input) 								{ m_Input = std::move(input); }

	private:
		std::unique_ptr<RendererAPI> m_RendererAPI;
		std::unique_ptr<AssetFactoryImpl> m_AssetFactory;
		std::unique_ptr<ShaderFactoryImpl> m_ShaderFactory;
		std::unique_ptr<TextureFactoryImpl> m_TextureFactory;

		std::unique_ptr<InputImpl> m_Input;
	};
}
