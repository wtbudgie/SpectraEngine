#pragma once

#include "Core.h"
#include "Core/Event/Event.h"

namespace Spectra {
	class SPECTRA_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}