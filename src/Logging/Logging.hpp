#pragma once
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <string>

namespace Core
{

	// Logging: Singleton class that gives the user info, warnings, and error messages 
	class Logging
	{
	private:
		// The Core Logging Class that tells info about the core library
		static std::shared_ptr<spdlog::logger> CoreLogger;
		// The App Logger which the user can use to debug info
		static std::shared_ptr<spdlog::logger> AppLogger; 
	private:
		// Singleton Design Pattern
		Logging() {} 
	public:
		// Singleton Design Pattern
		Logging(Logging const&) = delete;
        void operator=(Logging const&) = delete;
		static Logging& getInstance();
		// Actual part of Logging Class
		// Initialize the Logger Class
		static void init();
		// Set the level of the Core Class 
		static void setCoreLevel(spdlog::level::level_enum* level);
		// Set the level of the App Class 
		static void setAppLevel(spdlog::level::level_enum* level);
		// Getters used for the preprocessor defines
		static std::shared_ptr<spdlog::logger>& getCoreLogger() { return CoreLogger; }
		// Getters used for the preprocessor defines
		static std::shared_ptr<spdlog::logger>& getAppLogger() { return AppLogger; }
	};
}

/* PREPROCESSOR DEFINES FOR EASY ACCESS TO LOGGER */

#define CORE_TRACE(...)    ::Core::Logging::getCoreLogger()->trace(__VA_ARGS__)
#define CORE_DEBUG(...)    ::Core::Logging::getCoreLogger()->debug(__VA_ARGS__)
#define CORE_INFO(...)     ::Core::Logging::getCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)     ::Core::Logging::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)    ::Core::Logging::getCoreLogger()->error(__VA_ARGS__)
#define CORE_CRITICAL(...) ::Core::Logging::getCoreLogger ()->critical(__VA_ARGS__)

#define DEBUG_TRACE(...)       ::Core::Logging::getAppLogger()->trace(__VA_ARGS__)
#define APP_DEBUG(...)		   ::Core::Logging::getAppLogger()->debug(__VA_ARGS__)
#define APP_INFO(...)          ::Core::Logging::getAppLogger()->info(__VA_ARGS__)
#define APP_WARN(...)          ::Core::Logging::getAppLogger()->warn(__VA_ARGS__)
#define APP_ERROR(...)         ::Core::Logging::getAppLogger()->error(__VA_ARGS__)
#define APP_CRITICAL(...)      ::Core::Logging::getAppLogger()->critical(__VA_ARGS__)