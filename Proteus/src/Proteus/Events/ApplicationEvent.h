#pragma once
#include "Event.h"

//#include <sstream>

namespace Proteus {

	class PROTEUS_API WindowResizeEvent : public Event {
		unsigned int m_Width, m_Height;
		public:
			WindowResizeEvent(unsigned int width, unsigned int height)
				:m_Width(width), m_Height(height){}

			inline unsigned int GetWindowWidth() { return m_Width; }
			inline unsigned int GetWindowHeight() { return m_Height; }

			std::string ToString() const override {
				std::stringstream ss;
				ss << "WindowResizeEvent: [" << m_Width << "," << m_Height << "]";
				return ss.str();
			}

			EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class PROTEUS_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class PROTEUS_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class PROTEUS_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class PROTEUS_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}