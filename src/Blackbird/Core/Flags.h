#pragma once

// Target Define
#ifdef TARGET_DEBUG
#define BLACKBIRD_DEBUG
#endif

#ifdef TARGET_RELEASE
#define BLACKBIRD_RELEASE
#endif

#ifdef TARGET_DIST
#define BLACKBIRD_DIST
#endif


// Architecture Define
#ifdef ARCHITECTURE_X86
#define BLACKBIRD_X86
#endif

#ifdef ARCHITECTURE_X64
#define BLACKBIRD_X64
#endif


// Platform Define 
#ifdef PLATFORM_WINDOWS
#define BLACKBIRD_PLATFORM_WINDOWS
#endif

#ifdef PLATFORM_LINUX
#define BLACKBIRD_PLATFORM_LINUX
#endif


// Compiler Define
#ifdef COMPILER_VS
#define BLACKBIRD_COMPILER_VS
#endif

#ifdef COMPILER_GMAKE
#define BLACKBIRD_COMPILER_GMAKE
#endif

#define BLACKBIRD_RENDERER_OPENGL

