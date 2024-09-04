#pragma once

#include "Spectra/Core.h"
#include "Spectra/Core/Event/Event.h"

namespace Spectra {
	struct WindowProps {
		RendererPlatforms RendererPlatform;
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "SpectraEngine", unsigned int width = 1280, unsigned int height = 720, RendererPlatforms platform = RendererPlatforms::DX11) : 
			Title(title), Width(width), Height(height), RendererPlatform(platform) {}
	};

	class SPECTRA_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}