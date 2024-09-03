#pragma once

#include "Event.h"

namespace Spectra {
	class SPECTRA_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : mWidth(width), mHeight(height) {}

		inline float GetWidth() const { return mWidth; }
		inline float GetHeight() const { return mHeight; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << GetWidth() << ", " << GetHeight();
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int mWidth, mHeight;
	};

	class SPECTRA_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int mWidth, mHeight;
	};

	class SPECTRA_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SPECTRA_API AppUpdateEvent : public Event{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SPECTRA_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}