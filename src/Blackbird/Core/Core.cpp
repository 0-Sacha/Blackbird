#include "Core.h"

ProjectCore::LoggerManager::BasicLogger& Blackbird::Core::Logger()
{
	static ProjectCore::LoggerManager::BasicLogger instance("Blackbird");
	return instance;
}
