#pragma once

#ifdef SA_PLATFORM_WINDOWS
	#ifdef SA_BUILD_DLL
		#define SPECTRA_API __declspec(dllexport)
	#else
		#define SPECTRA_API __declspec(dllimport)
	#endif

#else
#error SpectraEngine is only supported on the Windows OS.
#endif

#define BIT(x) (1 << x)