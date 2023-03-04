#include "LayerStack.h"

namespace Blackbird
{

	void LayerStack::PushLayer(Ref<Layer>& layer)
	{
		m_Layers.emplace_back(layer);
		layer->OnAttachLayer(m_ApplicationLinked);
	}

	void LayerStack::PushOverlay(Ref<Layer>& overlay)
	{
		m_Overlay.push_back(overlay);
		overlay->OnAttachLayer(m_ApplicationLinked);
	}

	void LayerStack::PopLayer(Ref<Layer>& layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin(), layer);
		if (it != m_Layers.end())
		{
			(*it)->OnDetachLayer(m_ApplicationLinked);
			m_Layers.erase(it);
		}
	}

	void LayerStack::PopOverlay(Ref<Layer>& overlay)
	{
		auto it = std::find(m_Overlay.begin(), m_Overlay.end(), overlay);
		if (it != m_Overlay.end())
		{
			(*it)->OnDetachLayer(m_ApplicationLinked);
			m_Overlay.erase(it);
		}
	}

}
