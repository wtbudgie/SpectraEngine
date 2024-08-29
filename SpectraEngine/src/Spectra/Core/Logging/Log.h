#pragma once

#include "Spectra/Core.h"
#include <spdlog/spdlog.h>

namespace Spectra {
	class SPECTRA_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return mCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return mClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> mCoreLogger;
		static std::shared_ptr<spdlog::logger> mClientLogger;
	};
}

#define SA_CORE_TRACE(...)  ::Spectra::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SA_CORE_INFO(...)   ::Spectra::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SA_CORE_WARN(...)   ::Spectra::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SA_CORE_ERROR(...)  ::Spectra::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define SA_TRACE(...)       ::Spectra::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SA_INFO(...)        ::Spectra::Log::GetClientLogger()->info(__VA_ARGS__)
#define SA_WARN(...)        ::Spectra::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SA_ERROR(...)       ::Spectra::Log::GetClientLogger()->critical(__VA_ARGS__)
