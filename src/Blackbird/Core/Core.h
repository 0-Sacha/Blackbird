#pragma once

#include "ProjectCore/LoggerManager/LoggerManager.h"

#include <utility>
#include <memory>

namespace Blackbird
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T>
	using Ref = std::shared_ptr<T>;
	
	class Core
	{
	public:
		static ProjectCore::LoggerManager::BasicLogger& Logger();
	};

	class BlackbirdException : public std::exception
	{
	public:
		BlackbirdException(const char* msg)
			: std::exception(msg)
		{}

		~BlackbirdException() override = default;
	};
}


#ifdef BLACKBIRD_TARGET_DEBUG
	#define BLACKBIRD_ENABLE_ASSERTS
	#define BLACKBIRD_ENABLE_LOGGER

	#define BLACKBIRD_ENABLE_EVENT_TRACE
#endif

#ifdef BLACKBIRD_ENABLE_LOGGER
	#define BLKBID_TRACE(...)	Blackbird::Core::Logger().Trace(__VA_ARGS__)
	#define BLKBID_DEBUG(...)	Blackbird::Core::Logger().Debug(__VA_ARGS__)
	#define BLKBID_INFO(...)		Blackbird::Core::Logger().Info(__VA_ARGS__)
	#define BLKBID_WARN(...)		Blackbird::Core::Logger().Warn(__VA_ARGS__)
	#define BLKBID_ERROR(...)	Blackbird::Core::Logger().Error(__VA_ARGS__)
	#define BLKBID_FATAL(...)	Blackbird::Core::Logger().Fatal(__VA_ARGS__)
#else
	#define BLKBID_TRACE(...)
	#define BLKBID_DEBUG(...)
	#define BLKBID_INFO(...)
	#define BLKBID_WARN(...)
	#define BLKBID_ERROR(...)
	#define BLKBID_FATAL(...)
#endif


#ifdef BLACKBIRD_ENABLE_ASSERTS
	#define BLACKBIRD_ASSERT(x, ...) { if(!(x)) { Blackbird::Core::Logger().Fatal("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BLACKBIRD_ASSERT(x, ...)
#endif
