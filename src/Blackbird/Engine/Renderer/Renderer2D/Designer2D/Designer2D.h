#pragma once

#include "Designer2D.h"
#include "QuadDesigner.h"

namespace Blackbird
{
    class Designer2D
    {
    public:
        static QuadDesigner CreateQuadDesigner() { return QuadDesigner{}; }
    };
}
