#pragma once

#include "Blackbirdpch.h"

namespace Blackbird {
	class Core;
}

#ifdef BLACKBIRD_DEBUG
	#define BLACKBIRD_ENABLE_ASSERTS
	#define BLACKBIRD_ENABLE_LOGGER

	#define BLACKBIRD_ENABLE_EVENT_TRACE
#endif

#ifdef BLACKBIRD_ENABLE_LOGGER
	#define BLACKBIRD_TRACE(...)	Blackbird::Core::Logger().Trace(__VA_ARGS__)
	#define BLACKBIRD_INFO(...)		Blackbird::Core::Logger().Info(__VA_ARGS__)
	#define BLACKBIRD_WARN(...)		Blackbird::Core::Logger().Warn(__VA_ARGS__)
	#define BLACKBIRD_ERROR(...)	Blackbird::Core::Logger().Error(__VA_ARGS__)
	#define BLACKBIRD_FATAL(...)	Blackbird::Core::Logger().Fatal(__VA_ARGS__)
#else
	#define BLACKBIRD_TRACE(...)
	#define BLACKBIRD_INFO(...)
	#define BLACKBIRD_WARN(...)
	#define BLACKBIRD_ERROR(...)
	#define BLACKBIRD_FATAL(...)
#endif


#ifdef BLACKBIRD_ENABLE_ASSERTS
	#define BLACKBIRD_ASSERT(x, ...) { if(!(x)) { Blackbird::Core::Logger().Fatal("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BLACKBIRD_ASSERT(x, ...)
#endif


namespace Blackbird {
	
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
	
	class Core
	{
	public:
		static EngineCore::LoggerManager::BasicLogger& Logger();
	};
}

