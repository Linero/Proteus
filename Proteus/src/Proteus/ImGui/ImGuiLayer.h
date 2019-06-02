#pragma once

#include "Proteus/Layer.h"
#include "Proteus/Events/ApplicationEvent.h"
#include "Proteus/Events/KeyEvent.h"
#include "Proteus/Events/MouseEvent.h"

namespace Proteus {

	class PROTEUS_API ImGuiLayer : public Layer {
		float m_Time = 0.0f;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMoveEvent& e);
		bool OnMouseScrollEvent(MouseScrollEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

	};

}