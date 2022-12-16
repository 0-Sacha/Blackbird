#pragma once

#include "Blackbirdpch.h"

namespace Blackbird {
	class Core;
}

#ifdef BlACKBIRD_DEBUG
	#define BlACKBIRD_ENABLE_ASSERTS
	#define BlACKBIRD_ENABLE_LOGGER

	#define BlACKBIRD_ENABLE_EVENT_TRACE
#endif

#ifdef BlACKBIRD_ENABLE_LOGGER
	#define BlACKBIRD_TRACE(...)	Blackbird::Core::Logger().Trace(__VA_ARGS__)
	#define BlACKBIRD_INFO(...)		Blackbird::Core::Logger().Info(__VA_ARGS__)
	#define BlACKBIRD_WARN(...)		Blackbird::Core::Logger().Warn(__VA_ARGS__)
	#define BlACKBIRD_ERROR(...)	Blackbird::Core::Logger().Error(__VA_ARGS__)
	#define BlACKBIRD_FATAL(...)	Blackbird::Core::Logger().Fatal(__VA_ARGS__)
#else
	#define BlACKBIRD_TRACE(...)
	#define BlACKBIRD_INFO(...)
	#define BlACKBIRD_WARN(...)
	#define BlACKBIRD_ERROR(...)
	#define BlACKBIRD_FATAL(...)
#endif


#ifdef BlACKBIRD_ENABLE_ASSERTS
	#define BlACKBIRD_ASSERT(x, ...) { if(!(x)) { Blackbird::Core::Logger().Fatal("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BlACKBIRD_ASSERT(x, ...)
#endif


namespace Blackbird {
	
	using RendererID = unsigned int;

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

