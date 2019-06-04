#pragma once

#include "Proteus/Core.h"
#include "Layer.h"

namespace Proteus {

	class PROTEUS_API LayerStack {
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	};
}