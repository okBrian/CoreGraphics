#include "Logging.hpp"

namespace Core
{
	// The Core Logging Class that tells info about the core library
	std::shared_ptr<spdlog::logger> Logging::CoreLogger;
	// The App Logger which the user can use to debug info
	std::shared_ptr<spdlog::logger> Logging::AppLogger; 

	// Singleton Design Pattern
	Logging& Logging::getInstance()
	{
		static Logging instance; // Guaranteed to be destroyed.
								 // Instantiated on first use.
		return instance;	
	}

	// Initialize the Logger Class
	void Logging::init()
	{
		auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		sink->set_pattern("%^[%n][%l]%$ - %v");


		CoreLogger = std::make_shared<spdlog::logger>("CORE", sink);
		spdlog::register_logger(CoreLogger);
		CoreLogger->set_level(spdlog::level::err);
		CoreLogger->flush_on(spdlog::level::err);

		AppLogger = std::make_shared<spdlog::logger>("APP", sink);
		spdlog::register_logger(AppLogger);
		AppLogger->set_level(spdlog::level::err);
		AppLogger->flush_on(spdlog::level::err);
	}

	// Set the level of the Core Class 
	void Logging::setCoreLevel(spdlog::level::level_enum* level)
	{
		CoreLogger->set_level(*level);
	}

	// Set the level of the App Class 
	void Logging::setAppLevel(spdlog::level::level_enum* level)
	{
		AppLogger->set_level(*level);
	}
};