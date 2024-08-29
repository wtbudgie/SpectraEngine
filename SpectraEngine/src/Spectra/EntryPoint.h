#pragma once

#ifdef SA_PLATFORM_WINDOWS
	extern Spectra::Application* Spectra::CreateApplication();

	int main(int argc, char** argv) {
		Spectra::Log::Init();
		SA_CORE_WARN("Initalized Logging System.");

		auto app = Spectra::CreateApplication();
		app->Run();
		delete app;
	}

#endif