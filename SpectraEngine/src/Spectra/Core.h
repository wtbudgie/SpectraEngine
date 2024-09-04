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

#ifdef SA_ENABLE_ASSERTS
	#define SA_ASSERT(x, ...) { if(!(x)) { SA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SA_CORE_ASSERT(x, ...) { if(!(x)) { SA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SA_ASSERT(x, ...)
	#define SA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)