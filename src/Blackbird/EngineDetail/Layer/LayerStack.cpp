
#include "LayerStack.h"

namespace Blackbird
{
	LayerStack::LayerStack()
	{

	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIdx, layer);
		m_LayerInsertIdx++;
		layer->SetEngineContext(m_ApplicationRendererContext);
		layer->OnAttach();
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->SetEngineContext(m_ApplicationRendererContext);
		overlay->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIdx, layer);
		if (it != m_Layers.begin() + m_LayerInsertIdx)
		{
			layer->OnDetach();
			layer->ClearEngineContext();
			m_Layers.erase(it);
			m_LayerInsertIdx--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin() + m_LayerInsertIdx, m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetach();
			overlay->ClearEngineContext();
			m_Layers.erase(it);
		}
	}
}
