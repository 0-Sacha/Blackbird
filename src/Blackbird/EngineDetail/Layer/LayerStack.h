#pragma once

#include "Layer.h"

#include <ranges>

namespace Blackbird {

	class Application;
	
	class LayerStack
	{
	public:
		void PushLayer(Ref<Layer>& layer);
		void PushOverlay(Ref<Layer>& overlay);
		void PopLayer(Ref<Layer>& layer);
		void PopOverlay(Ref<Layer>& overlay);

	public:
		std::vector<Ref<Layer>>& GetLayers() 				{ return m_Layers; }
		const std::vector<Ref<Layer>>& GetLayers() const 	{ return m_Layers; }
		std::vector<Ref<Layer>>& GetOverlays() 				{ return m_Layers; }
		const std::vector<Ref<Layer>>& GetOverlays() const 	{ return m_Layers; }

	public:
		void ForEach(std::function<void(Ref<Layer>& layer)> function)
		{
			for (Ref<Layer>& layer : m_Layers)
				function(layer);
			for (Ref<Layer>& overlay : m_Overlay)
				function(overlay);
		}

		void ForEachReverse(std::function<void(Ref<Layer>& layer)> function)
		{
			for (Ref<Layer>& overlay : m_Overlay | std::views::reverse)
				function(overlay);
			for (Ref<Layer>& layer : m_Layers | std::views::reverse)
				function(layer);
		}

	private:
		Application* m_ApplicationLinked;
		std::vector<Ref<Layer>> m_Layers;
		std::vector<Ref<Layer>> m_Overlay;
	};

}