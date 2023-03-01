#pragma once

#include "Blackbird/Engine/Context/EngineContext.h"

namespace Blackbird
{
    class StaticContext
    {
    public:
        static inline EngineAPI& Engine() { return s_EngineContext.Engine(); }
        static inline PlatformAPI& Platform() { return s_EngineContext.Platform(); }
        static inline Renderer& GetRenderer() { return s_EngineContext.GetRenderer(); }
        static inline Renderer2D& GetRenderer2D() { return s_EngineContext.GetRenderer2D(); }

    public:
        static void SetEngineContext(EngineContext& context) { s_EngineContext = context; }

    private:
        static inline EngineContext s_EngineContext;
    };
}
