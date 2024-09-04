#pragma once

namespace Spectra {
	enum RendererPlatforms {
		DX11, DX12
	};

	const char* RendererPlatformToString(RendererPlatforms platform);
}