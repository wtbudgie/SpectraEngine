#pragma once

#include "Core.h"

namespace Spectra {
	class SPECTRA_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}