#pragma once

#include "Proteus/Window.h"
#include <GLFW/glfw3.h>

namespace Proteus {

	class WindowsWindow : public Window {
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
		GLFWwindow* m_Window;
		
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;

		};

		WindowData m_Data;
	};
}