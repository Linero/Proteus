#include "Proteus_pch.h"
#include <Proteus.h>

class ExampleLayer : public Proteus::Layer {

public:
	ExampleLayer()
		:Layer("Example") {}

	void OnUpdate() override {
		PROTEUS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Proteus::Event& event) override {
		PROTEUS_TRACE("{0}", event);
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
