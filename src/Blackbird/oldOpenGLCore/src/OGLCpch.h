#pragma once


// Target Define
#ifdef BASE_TARGET_DEBUG
	#define OGLC_DEBUG
#endif

#ifdef BASE_TARGET_RELEASE
	#define OGLC_RELEASE
#endif

#ifdef BASE_TARGET_DIST
	#define OGLC_DIST
#endif


// Architecture Define
#ifdef BASE_ARCHITECTURE_X86
	#error OGLC doesn't support x86
#endif

#ifdef BASE_ARCHITECTURE_X86_64
	#define OGLC_X64
#endif


// Platform Define 
#ifdef BASE_PLATFORM_WINDOWS
	#define OGLC_PLATFORM_WINDOWS
#endif

#ifdef BASE_PLATFORM_LINUX
	#error OGLC doesn't support Linux
#endif


// Compiler Define
#ifdef BASE_COMPILER_MSVC
#endif

#ifdef BASE_COMPILER_GCC
#endif





// Include
#include "CPPTools/LogSystem/LogSystem.h"

#include "CPPTools/Format/Container/Array.h"
#include "CPPTools/Format/Container/Deque.h"
#include "CPPTools/Format/Container/List.h"
#include "CPPTools/Format/Container/Map.h"
#include "CPPTools/Format/Container/Set.h"
#include "CPPTools/Format/Container/Tuple.h"
#include "CPPTools/Format/Container/Vector.h"

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

#ifdef OGLC_PLATFORM_WINDOWS
	#include <Windows.h>
#endif