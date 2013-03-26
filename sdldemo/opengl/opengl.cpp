#include "stdafx.h"

#include <gl/GL.h>
#include <gl/GLU.h>

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    SDL_Event event;

    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Surface* screen = SDL_SetVideoMode(1280, 960, 24, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);

    if( screen == NULL ) {
        return -1;
    }

    while( true ) {
            break;
        }

    }

    SDL_FreeSurface(screen);

    SDL_Quit();

    return 0;
}