// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BUNNYLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BUNNYLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BUNNYLIB_EXPORTS
#define BUNNYLIB_API __declspec(dllexport)
#else
#define BUNNYLIB_API __declspec(dllimport)
#endif

// This class is exported from the bunnylib.dll
class BUNNYLIB_API Cbunnylib {
public:
	Cbunnylib(void);
	// TODO: add your methods here.
};

extern BUNNYLIB_API int nbunnylib;

BUNNYLIB_API int fnbunnylib(void);
