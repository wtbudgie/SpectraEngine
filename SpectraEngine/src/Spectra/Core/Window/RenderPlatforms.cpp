#include "pch.h"
#include "RendererPlatforms.h"

namespace Spectra {
    const char* RendererPlatformToString(RendererPlatforms platform) {
        switch (platform) {
        case RendererPlatforms::DX11: return "DirectX11";
        case RendererPlatforms::DX12: return "DirectX12";
        default: return "Unknown renderer.";
        }
    }
}