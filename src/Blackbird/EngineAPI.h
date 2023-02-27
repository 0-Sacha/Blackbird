#pragma once

#include "Blackbird/Core/Core.h"

#include "Engine/Renderer/IRendererCommand.h"
#include "Engine/Asset/IAssetFactory.h"
#include "Engine/Shader/IShaderFactory.h"
#include "Engine/Texture/ITextureFactory.h"

#include "EngineDetail/Input/IInput.h"

namespace Blackbird
{
	class EngineAPI
	{
	public:
		static EngineAPI& GetInstance();

	public:
		IRendererCommand& GetRendererCommand() 	{ return *m_RendererCommand; }
		IAssetFactory& GetAssetFactory() 		{ return *m_AssetFactory; }
		IShaderFactory& GetShaderFactory() 		{ return *m_ShaderFactory; }
		ITextureFactory& GetTextureFactory() 	{ return *m_TextureFactory; }

		IInput& GetInput() 						{ return *m_Input; }

	public:
		void SetRendererCommand(std::unique_ptr<IRendererCommand>&& rendererCommand) 	{ m_RendererCommand = std::move(rendererCommand); }
		void SetAssetFactory(std::unique_ptr<IAssetFactory>&& assetFactory) 			{ m_AssetFactory = std::move(assetFactory); }
		void SetShaderFactory(std::unique_ptr<IShaderFactory>&& shaderFactory) 			{ m_ShaderFactory = std::move(shaderFactory); }
		void SetTextureFactory(std::unique_ptr<ITextureFactory>&& textureFactory) 		{ m_TextureFactory = std::move(textureFactory); }

		void SetInput(std::unique_ptr<IInput>&& input) 									{ m_Input = std::move(input); }

	private:
		std::unique_ptr<IRendererCommand> m_RendererCommand;
		std::unique_ptr<IAssetFactory> m_AssetFactory;
		std::unique_ptr<IShaderFactory> m_ShaderFactory;
		std::unique_ptr<ITextureFactory> m_TextureFactory;

		std::unique_ptr<IInput> m_Input;
	};
}
