
#include "Blackbirdpch.h"
#include "Layer.h"

namespace Blackbird {
	
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName) {}

	Layer::Layer(std::string&& debugName)
		: m_DebugName(std::move(debugName)) {}
}