#pragma once


// Not sur that all of this is needed
#include "imgui.h"

#include "Blackbird/Core/Input/Input.h"
#include "Blackbird/Core/Application/Application.h"
#include "Blackbird/ImGui/ImGuiLayer.h"

#include "Blackbird/Renderer/Shader/Shader.h"
#include "Blackbird/Renderer/Shader/ShaderLoader.h"
#include "Blackbird/Renderer/Asset/VertexBuffer.h"
#include "Blackbird/Renderer/Asset/VertexArray.h"
#include "Blackbird/Renderer/Asset/VertexBufferLayout.h"
#include "Blackbird/Renderer/Camera/OrthographicCamera.h"
#include "Blackbird/Renderer/Camera/OrthographicCameraController.h"

#include "Blackbird/Renderer/Renderer.h"
#include "Blackbird/Renderer/RendererAPI.h"
#include "Blackbird/Renderer/RendererCommand.h"
#include "Blackbird/Renderer/Context/RendererContext.h"


#include "Platform/OpenGL/Utils/Debug/OpenGlDebug.h"

/////---------- Entry Point ----------/////
#include "Blackbird/Core/EntryPoint.h"
/////---------------------------------/////