#include "Logging.hpp"

namespace Core
{

	void Logging::errorImpl(std::string errorMsg)
	{
		spdlog::error(errorMsg);
		throw(errno);
	}

	void Logging::criticalImpl(std::string errorMsg)
	{
		spdlog::critical(errorMsg);
		throw(errno);
	}

	void Logging::warningImpl(std::string warningMsg)
	{
		spdlog::warn(warningMsg);
	}
};