#include "Proteus_pch.h"
#include "Application.h"
#include "Proteus/Events/ApplicationEvent.h"
#include "Proteus/Events/KeyEvent.h"
#include "Proteus/Events/MouseEvent.h"
#include "Proteus/Log.h"


namespace Proteus {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PROTEUS_TRACE(e);
		while (true);
	}

}
