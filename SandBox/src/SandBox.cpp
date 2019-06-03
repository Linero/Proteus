#include <Proteus.h>

class ExampleLayer : public Proteus::Layer {

public:
	ExampleLayer()
		:Layer("Example") {}

	void OnUpdate() override {
		//PROTEUS_INFO("ExampleLayer::Update");
		if (Proteus::Input::IsKeyPressed(PROTEUS_KEY_A)) PROTEUS_TRACE("Key A pressed [poll]");
	}

	void OnEvent(Proteus::Event& event) override {
		//PROTEUS_TRACE("{0}", event);
		if (event.GetEventType() == Proteus::EventType::KeyPressed) {
			Proteus::KeyPressedEvent& e = (Proteus::KeyPressedEvent&)event;
			if (Proteus::Input::IsKeyPressed(PROTEUS_KEY_A)) PROTEUS_TRACE("Key A pressed [event]");
			PROTEUS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};


class SandBox : public Proteus::Application {

public:

	SandBox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Proteus::ImGuiLayer());
	}
	~SandBox() {
		
	}
};

Proteus::Application* Proteus::CreateApplication() {
	return new SandBox();
}
