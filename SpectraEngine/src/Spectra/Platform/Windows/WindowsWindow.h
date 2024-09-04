#pragma once

#include "Spectra/Core/Window/Window.h"

#include "Windows.h"

#define COMPTR Microsoft::WRL::ComPtr

namespace Spectra {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return mData.Width; }
		inline unsigned int GetHeight() const override { return mData.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { mData.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	private:
		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		const RendererPlatforms mRenderPlatform;
		WindowData mData;
		HWND mWindow;
	};
}
