
#include "Blackbirdpch.h"

#include "Core.h"

EngineCore::LoggerManager::BasicLogger& Blackbird::Core::Logger()
{
	static EngineCore::LoggerManager::BasicLogger instance("Blackbird");
	return instance;
}
