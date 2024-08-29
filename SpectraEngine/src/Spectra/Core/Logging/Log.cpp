#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Spectra {
	std::shared_ptr<spdlog::logger> Log::mCoreLogger;
	std::shared_ptr<spdlog::logger> Log::mClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		mCoreLogger = spdlog::stdout_color_mt("SpectraEngine");
		mCoreLogger->set_level(spdlog::level::trace);

		mClientLogger = spdlog::stdout_color_mt("Application");
		mClientLogger->set_level(spdlog::level::trace);
	}
}