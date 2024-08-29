#include <SpectraEngine.h>

class Sandbox : public Spectra::Application
{
public:
	Sandbox() { }
	~Sandbox() { }

};

Spectra::Application* Spectra::CreateApplication() {
	return new Sandbox();
}