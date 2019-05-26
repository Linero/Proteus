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

#define BIT(x) (1 << x)