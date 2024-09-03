#include "pch.h"

#include "Application.h"

#include "Spectra/Core/Event/ApplicationEvent.h"
#include "Spectra/Core/Logging/Log.h"

namespace Spectra {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		SA_TRACE(e.ToString());

		while (true);
	}
}