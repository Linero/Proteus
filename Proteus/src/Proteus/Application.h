#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "LayerStack.h"
#include "Window.h"

namespace Proteus {
	class PROTEUS_API Application
	{
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}

