#pragma once


// Target Define
#ifdef BASE_TARGET_DEBUG
	#define SPITFIRE_DEBUG
#endif

#ifdef BASE_TARGET_RELEASE
	#define SPITFIRE_RELEASE
#endif

#ifdef BASE_TARGET_DIST
	#define SPITFIRE_DIST
#endif


// Architecture Define
#ifdef BASE_ARCHITECTURE_X86
	#error Spitfire doesn't support x86
#endif

#ifdef BASE_ARCHITECTURE_X86_64
	#define SPITFIRE_X64
#endif


// Platform Define 
#ifdef BASE_PLATFORM_WINDOWS
	#define SPITFIRE_PLATFORM_WINDOWS
#endif

#ifdef BASE_PLATFORM_LINUX
	#error Spitfire doesn't support Linux
#endif


// Compiler Define
#ifdef BASE_COMPILER_MSVC
#endif

#ifdef BASE_COMPILER_GCC
#endif





// Include
#include "EngineCore/Instrumentation/Formatter/Format/Container/AllContainer.h"
#include "EngineCore/Instrumentation/LoggerManager/BasicLogger.h"

// Container
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <vector>
#include <string>
#include <sstream>


#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <functional>
#include <memory>

#ifdef SPITFIRE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif


#ifdef SPITFIRE_PLATFORM_WINDOWS
	#define SPITFIRE_RENDERER_OPENGL
#endif
