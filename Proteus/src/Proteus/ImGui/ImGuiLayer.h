#pragma once

#include "Proteus/Layer.h"

namespace Proteus {

	class PROTEUS_API ImGuiLayer : public Layer {
		float m_Time;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	};

}