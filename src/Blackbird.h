#pragma once


// Not sure that all of this is needed
#include "imgui.h"

#include "Blackbird/EngineDetail/Input/Input.h"
#include "Blackbird/EngineDetail/Application/Application.h"
#include "Blackbird/ImGui/ImGuiLayer.h"

#include "Blackbird/Engine/Shader/Shader.h"
#include "Blackbird/Engine/Shader/ShaderFactory.h"
#include "Blackbird/Engine/Shader/ShaderLibrary.h"
#include "Blackbird/Engine/Texture/Texture.h"
#include "Blackbird/Engine/Texture/TextureFactory.h"
#include "Blackbird/Engine/Asset/VertexBuffer.h"
#include "Blackbird/Engine/Asset/VertexArray.h"
#include "Blackbird/Engine/Asset/VertexBufferLayout.h"
#include "Blackbird/Engine/Asset/AssetFactory.h"
#include "Blackbird/Engine/Camera/OrthographicCamera.h"
#include "Blackbird/EngineUtils/OrthographicCameraController/OrthographicCameraController.h"

#include "Blackbird/Engine/Renderer/Renderer.h"
#include "Blackbird/Engine/Renderer/Renderer2D/Renderer2D.h"
#include "Blackbird/Engine/Renderer/Renderer2D/Designer2D/Designer2D.h"
#include "Blackbird/Engine/Renderer/RendererCommand.h"
#include "Blackbird/Engine/Context/RendererContext.h"


#include "Platform/GraphicsPlatform/OpenGL/Utils/Debug/OpenGlDebug.h"
