#pragma once
#include <spdlog/spdlog.h>
#include <string>

namespace Core
{

	// Logging: Give user info about errors and warnings 
	class Logging
	{
	public:
		Logging(const Logging&) = delete;

		static Logging& Get()
		{
			static Logging _Instance;
			return _Instance;
		}
		
		static void error(std::string errorMsg) { return Get().errorImpl(errorMsg); }
		static void critical(std::string errorMsg) { return Get().criticalImpl(errorMsg); }
		static void warning(std::string warningMsg) { return Get().warningImpl(warningMsg); }
	private:
		Logging() {}
		void errorImpl(std::string errorMsg);
		void criticalImpl(std::string errorMsg);
		void warningImpl(std::string warningMsg);
	};
}