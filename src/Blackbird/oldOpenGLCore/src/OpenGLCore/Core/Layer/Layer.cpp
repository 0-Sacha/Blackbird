
#include "OGLCpch.h"
#include "Layer.h"

namespace OGLC {
	
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName) {}

	Layer::Layer(std::string&& debugName)
		: m_DebugName(std::move(debugName)) {}
}