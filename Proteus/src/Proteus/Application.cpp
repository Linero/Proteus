#include "Proteus_pch.h"
#include "Application.h"
#include "Proteus/Events/ApplicationEvent.h"
#include "Proteus/Events/KeyEvent.h"
#include "Proteus/Events/MouseEvent.h"
#include "Proteus/Log.h"
#include "GLFW/glfw3.h"


namespace Proteus {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PROTEUS_TRACE(e);
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}
