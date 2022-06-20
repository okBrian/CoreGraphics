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
		auto console = spdlog::stdout_color_mt("console");
		
		CoreLogger = std::make_shared<spdlog::logger>("CORE");
		CoreLogger->set_pattern("%^[%n][%l][%@]%$ - %v");
		spdlog::register_logger(CoreLogger);
		CoreLogger->set_level(spdlog::level::debug);
		CoreLogger->flush_on(spdlog::level::debug);

		AppLogger = std::make_shared<spdlog::logger>("APP");
		AppLogger->set_pattern("%^[%n][%l][%@]%$ - %v");
		spdlog::register_logger(AppLogger);
		AppLogger->set_level(spdlog::level::debug);
		AppLogger->flush_on(spdlog::level::debug);
	}

	// Set the level of the Core Class 
	void Logging::setCoreLevel(spdlog::level::level_enum level)
	{
		CoreLogger->set_level(level);
	}

	// Set the level of the App Class 
	void Logging::setAppLevel(spdlog::level::level_enum level)
	{
		AppLogger->set_level(level);
	}
};