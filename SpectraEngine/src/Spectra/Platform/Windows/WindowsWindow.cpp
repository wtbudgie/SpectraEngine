#include "pch.h"
#include "WindowsWindow.h"

#define MAX_NAME_STRING 256
WCHAR WindowTitle[MAX_NAME_STRING];

namespace Spectra {
    static bool sWinAPIInitialized = false;

    WindowsWindow::WindowsWindow(const WindowProps& props) : mRenderPlatform(props.RendererPlatform) {
        Init(props);
    }

    WindowsWindow::~WindowsWindow() {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps& props) {
        mData.Title = props.Title;
        mData.Width = props.Width;
        mData.Height = props.Height;

        std::wstring windowTitle(mData.Title.begin(), mData.Title.end());
        wcscpy_s(WindowTitle, windowTitle.c_str());

        SA_CORE_INFO("Initializing window using {0}.", RendererPlatformToString(mRenderPlatform));
        SA_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!sWinAPIInitialized) {
            WNDCLASSEX wc = {};

            wc.cbSize = sizeof(WNDCLASSEX);
            wc.style = CS_HREDRAW | CS_VREDRAW;
            wc.cbClsExtra = 0;
            wc.cbWndExtra = 0;

            wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
            wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

            wc.hIcon = LoadIcon(0, IDI_APPLICATION);
            wc.hIconSm = LoadIcon(0, IDI_APPLICATION);

            wc.lpszClassName = WindowTitle;
            wc.lpszMenuName = WindowTitle;

            wc.hInstance = GetModuleHandle(nullptr);

            wc.lpfnWndProc = WindowProc;

            RegisterClassEx(&wc);

            sWinAPIInitialized = true;
        }

        RECT windowRect = { 0, 0, (LONG)props.Width, (LONG)props.Height };
        AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

        mWindow = CreateWindowEx(
            0,
            WindowTitle,
            WindowTitle,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            windowRect.right - windowRect.left,
            windowRect.bottom - windowRect.top,
            nullptr,
            nullptr,
            GetModuleHandle(nullptr),
            this
        );

        SA_CORE_ASSERT(mWindow, "Failed to create window!");

        SetWindowLongPtr(mWindow, GWLP_USERDATA, (LONG_PTR)this);

        ShowWindow(mWindow, SW_SHOW);
        UpdateWindow(mWindow);
    }

    void WindowsWindow::Shutdown() {
        DestroyWindow(mWindow);
    }

    void WindowsWindow::OnUpdate() {
        // Event Polling
        MSG msg = {};
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        //mDX12Factory.GetSwapChain()->Present(mData.VSync ? 1 : 0, 0);
    }

    void WindowsWindow::SetVSync(bool enabled) {
        mData.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const {
        return mData.VSync;
    }
}

LRESULT CALLBACK Spectra::WindowsWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    WindowsWindow* window = reinterpret_cast<WindowsWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (window) {
        switch (uMsg) {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_SIZE:
            // Window resize
            break;
        }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
