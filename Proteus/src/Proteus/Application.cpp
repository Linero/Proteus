#include "Proteus_pch.h"
#include "Application.h"
#include "Proteus/Log.h"
#include "glad/glad.h"
#include "Input.h"
#include "glm/glm.hpp"

namespace Proteus {

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		PROTEUS_CORE_ASSERT(!s_Instance, "Application already exist!")
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		//WindowResizeEvent e(1280, 720);
		//PROTEUS_TRACE(e);
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			for (Layer* layer : m_LayerStack) layer->OnUpdate();

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack) m_ImGuiLayer->OnImGuiRender();
			m_ImGuiLayer->End();

			//auto [x, y] = Input::GetMousePos();
			//PROTEUS_CORE_TRACE("{0},{1}", x, y);

			//PROTEUS_CORE_TRACE("{0}", Input::IsKeyPressed(65)); // trace key: a
			//PROTEUS_CORE_TRACE("{0}", Input::IsMouseButtonPressed(0)); // trace: left mouse button

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		// THIS
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		// OR
		//dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent & e) -> bool { return OnWindowClose(e); });

		//PROTEUS_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
