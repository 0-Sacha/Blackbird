#pragma once

#include "OGLCpch.h"

namespace OGLC {
	class Core;
}

#ifdef OGLC_DEBUG
	#define OGLC_ENABLE_ASSERTS
	#define OGLC_ENABLE_LOGGER

	#define OGLC_ENABLE_EVENT_TRACE
#endif

#ifdef OGLC_ENABLE_LOGGER
	#define OGLC_TRACE(...) OGLC::Core::Logger().LogTrace(__VA_ARGS__)
	#define OGLC_INFO(...)	OGLC::Core::Logger().LogInfo(__VA_ARGS__)
	#define OGLC_WARN(...)	OGLC::Core::Logger().LogWarn(__VA_ARGS__)
	#define OGLC_ERROR(...) OGLC::Core::Logger().LogError(__VA_ARGS__)
	#define OGLC_FATAL(...) OGLC::Core::Logger().LogFatal(__VA_ARGS__)
#else
	#define OGLC_TRACE(...)
	#define OGLC_INFO(...)
	#define OGLC_WARN(...)
	#define OGLC_ERROR(...)
	#define OGLC_FATAL(...)
#endif

#ifdef OGLC_ENABLE_ASSERTS
	#define OGLC_ASSERT(x, ...) { if(!(x)) { OGLC::Core::Logger().LogFatal("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
	#define OGLC_ASSERT(x, ...)
#endif


namespace OGLC {
	
	using RendererID = unsigned int;

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
	
	class Core
	{
	public:
		static CPPTools::LogSystem& Logger();
	};
}

