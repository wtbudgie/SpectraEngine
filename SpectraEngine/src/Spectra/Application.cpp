#include "pch.h"

#include "Application.h"

#include "Spectra/Core/Event/ApplicationEvent.h"
#include "Spectra/Core/Logging/Log.h"

namespace Spectra {
	Application::Application() : mRunning(true) {
		mWindow = std::unique_ptr<Window>(Window::Create());

		if (!mWindow) {
			SA_CORE_ERROR("Failed to create window!");
			mRunning = false;
		}
	}

	Application::~Application() {}

	void Application::Run() {
		while (mRunning) {
			mWindow->OnUpdate();
		};
	}
}