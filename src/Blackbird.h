#pragma once


// Not sure that all of this is needed
#include "imgui.h"

#include "Blackbird/EngineDetail/Application/Application.h"
#include "Blackbird/ImGui/ImGuiLayer.h"

#include "Blackbird/Engine/Shader/Shader.h"
#include "Blackbird/Engine/Shader/ShaderLibrary.h"
#include "Blackbird/Engine/Texture/Texture.h"
#include "Blackbird/Engine/Asset/VertexBuffer.h"
#include "Blackbird/Engine/Asset/VertexArray.h"
#include "Blackbird/Engine/Asset/VertexBufferLayout.h"
#include "Blackbird/Engine/Camera/OrthographicCamera.h"
#include "Blackbird/EngineUtils/OrthographicCameraController/OrthographicCameraController.h"

#include "Blackbird/Engine/Renderer/Renderer.h"
#include "Blackbird/Engine/Renderer2D/Renderer2D.h"
#include "Blackbird/Engine/IRendererCommand.h"

#include "Platform/GraphicsPlatform/OpenGL/Utils/Debug/OpenGlDebug.h"


#include "Blackbird/Engine/Static/S_Input.h"
#include "Blackbird/Engine/Static/S_AssetFactory.h"
#include "Blackbird/Engine/Static/S_ShaderFactory.h"
#include "Blackbird/Engine/Static/S_TextureFactory.h"
#include "Blackbird/Engine/Static/S_RendererCommand.h"
#include "Blackbird/Engine/Static/S_Renderer.h"
#include "Blackbird/Engine/Static/S_Renderer2D.h"
