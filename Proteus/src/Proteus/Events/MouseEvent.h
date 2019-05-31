#pragma once
#include "Event.h"


namespace Proteus {

	class PROTEUS_API MouseMoveEvent : public Event {
		float m_MouseX, m_MouseY;
	public:
		MouseMoveEvent(float x, float y)
			:m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMoveEvent: [" << GetX() << "," << GetY() << "]";
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)


	};


	class PROTEUS_API MouseScrollEvent : public Event {
		float m_OffsetX, m_OffsetY;
	public:
		MouseScrollEvent(float xOffset, float yOffset)
			:m_OffsetX(xOffset), m_OffsetY(yOffset) {}

		inline float GetOffsetX() const { return m_OffsetX; }
		inline float GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrollEvent: [" << GetOffsetX() << "," << GetOffsetY() << "]";
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class PROTEUS_API MouseButtonEvent : public Event {

	public:

		inline int GetButton() const { return m_Buton; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonEvent: [" << GetButton() << "]";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button)
			:m_Buton(button) {}

		int m_Buton;
	};


	class PROTEUS_API MouseButtonPressedEvent : public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(int& button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: [" << m_Buton << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};


	class PROTEUS_API MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(int& button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: [" << m_Buton << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};


}