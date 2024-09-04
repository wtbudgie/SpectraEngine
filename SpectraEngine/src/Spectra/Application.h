#pragma once

#include "Core.h"
#include "Core/Event/Event.h"
#include "Core/Window/Window.h"

namespace Spectra {
	class SPECTRA_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> mWindow;
		bool mRunning = true;
	};

	Application* CreateApplication();
}