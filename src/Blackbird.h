#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

#include "Blackbird/Engine/Renderer/Renderer.h"
#include "Blackbird/Engine/Renderer2D/Renderer2D.h"
#include "Blackbird/Engine/IRendererCommand.h"

#include "Blackbird/Scene/Scene2D.h"
#include "Blackbird/Scene/Entity.h"
#include "Blackbird/Scene/Components.h"
#include "Blackbird/Scene/NativeScript.h"

#include "Blackbird/Engine/BlackbirdStatic/BlackbirdStatic.h"

#include "Platform/GraphicsPlatform/OpenGL/Utils/Debug/OpenGlDebug.h"
