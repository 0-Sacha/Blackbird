#pragma once

#include "Blackbird/EngineAPI.h"

#include "Platform/GraphicsPlatform/GraphicsPlatform.h"

#include "Blackbird/EngineDetail/Window.h"

namespace Blackbird
{
    class PlatformAPI;
}

namespace Blackbird::WindowPlatform
{
    class IWindowPlatform
    {
    public:
        virtual void InitEngineAPI(EngineAPI& api) = 0;
        virtual Scope<Window> CreateWindow(const WindowProps& props, PlatformAPI& api) = 0;
	};
}
