#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Proteus/Events/ApplicationEvent.h"
#include "Proteus/Events/KeyEvent.h"
#include "Proteus/Events/MouseEvent.h"
#include "Proteus/Window.h"

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

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	};

	// To be defined in client
	Application* CreateApplication();
}

