#include "pch.h"
#include "Window.h"

#include "Spectra/Platform/Windows/WindowsWindow.h"

namespace Spectra {
	Window* Window::Create(const WindowProps& props) {
        return new WindowsWindow(props);
    }
}