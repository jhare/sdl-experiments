// bunnylib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "bunnylib.h"


// This is an example of an exported variable
BUNNYLIB_API int nbunnylib=0;

// This is an example of an exported function.
BUNNYLIB_API int fnbunnylib(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see bunnylib.h for the class definition
Cbunnylib::Cbunnylib()
{
	return;
}
