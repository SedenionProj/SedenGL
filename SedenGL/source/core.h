#pragma once
#ifdef SEDEN_PLATFORM_WINDOWS
	#ifdef SEDEN_BUILD
		#define SEDEN __declspec(dllexport)
	#else
		#define SEDEN __declspec(dllimport)
	#endif
#endif