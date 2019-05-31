#pragma once

#ifdef PROTEUS_PLATFORM_WIN
	#ifdef PROTEUS_BUILD_DLL
		#define PROTEUS_API	__declspec(dllexport)
	#else
		#define PROTEUS_API	__declspec(dllimport)
	#endif // PROTEUS_BUILD_DLL
#else
	#error Proteus only support WIN x64 
#endif // PROTEUS_PLATFORM_WIN

#ifdef PROTEUS_ENABLE_ASSERTS
	#define PROTEUS_ASSERT(x, ...) {if(!(x)){ PROTEUS_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak(); } }
	#define PROTEUS_CORE_ASSERT(x, ...) {if(!(x)){ PROTEUS_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak(); } }
#else
	#define PROTEUS_ASSERT(x, ...)
	#define PROTEUS_CORE_ASSERT(x, ...)
#endif // PROTEUS_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)