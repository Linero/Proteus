#pragma once
#include "Core.h"
#include "Events/Event.h"
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

	};

	// To be defined in client
	Application* CreateApplication();
}

