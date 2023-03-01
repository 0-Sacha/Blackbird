#pragma once

#include "Blackbird/Core/Core.h"

#include "Engine/IRendererCommand.h"
#include "Engine/Asset/IAssetFactory.h"
#include "Engine/Shader/IShaderFactory.h"
#include "Engine/Texture/ITextureFactory.h"

#include "EngineDetail/Input/IInput.h"

namespace Blackbird
{
	class EngineAPI
	{
	public:
		IRendererCommand& RendererCommand() { return *m_RendererCommand; }
		IAssetFactory& AssetFactory() 		{ return *m_AssetFactory; }
		IShaderFactory& ShaderFactory() 	{ return *m_ShaderFactory; }
		ITextureFactory& TextureFactory() 	{ return *m_TextureFactory; }

		IInput& Input() 					{ return *m_Input; }

	public:
		void Init()
		{
			m_RendererCommand->Init();
		}

		void Shutdown()
		{
			m_RendererCommand->Shutdown();
		}

	public:
		void SetRendererCommand(Scope<IRendererCommand>&& rendererCommand) 	{ m_RendererCommand = std::move(rendererCommand); }
		void SetAssetFactory(Scope<IAssetFactory>&& assetFactory) 			{ m_AssetFactory = std::move(assetFactory); }
		void SetShaderFactory(Scope<IShaderFactory>&& shaderFactory) 		{ m_ShaderFactory = std::move(shaderFactory); }
		void SetTextureFactory(Scope<ITextureFactory>&& textureFactory) 	{ m_TextureFactory = std::move(textureFactory); }

		void SetInput(Scope<IInput>&& input) 								{ m_Input = std::move(input); }

	private:
		Scope<IRendererCommand> m_RendererCommand;
		Scope<IAssetFactory> m_AssetFactory;
		Scope<IShaderFactory> m_ShaderFactory;
		Scope<ITextureFactory> m_TextureFactory;

		Scope<IInput> m_Input;
	};
}
