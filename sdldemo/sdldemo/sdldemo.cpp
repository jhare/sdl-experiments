// sdldemo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "sdldemomain.h"
#include "SDL.h"

using namespace std;
using namespace SDLDemo;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	SDLDemoMain demoMain;

	if( demoMain.Initialize() == 0 ) {

		while( demoMain.Events() == true ) {
			demoMain.Loop();
			demoMain.Render();
		}
	}

	return demoMain.Shutdown();
}