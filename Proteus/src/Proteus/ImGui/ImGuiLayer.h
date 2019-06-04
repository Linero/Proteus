#pragma once

#include "Proteus/Layer.h"
#include "Proteus/Events/ApplicationEvent.h"
#include "Proteus/Events/KeyEvent.h"
#include "Proteus/Events/MouseEvent.h"

namespace Proteus {

	class PROTEUS_API ImGuiLayer : public Layer {
		float m_Time;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		//virtual void OnUpdate() override;

		void Begin();
		void End();
	};

}