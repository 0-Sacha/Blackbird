#pragma once

#include "Blackbird/EngineAPI.h"

#include "Platform/GraphicsPlatform/GraphicsPlatform.h"

namespace Blackbird::WindowPlatform
{
    class IWindowPlatform
    {
    public:
        virtual void InitEngineAPI(EngineAPI& api) = 0;
	};
}
