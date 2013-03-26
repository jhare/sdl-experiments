// sdldemo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SDL.h"

using namespace std;

SDL_Surface* getSurface(char* fileName) {

    // Load up the original BMP and set up a ptr to the formatted one.
    SDL_Surface* original = SDL_LoadBMP(fileName);
    SDL_Surface* formattedBMP = NULL;
    if( original == NULL) {
        return NULL;
    }

    // Convert BMP's display format to the one SDL wants.
    formattedBMP = SDL_DisplayFormat(original);

    // We're done with the old
    SDL_FreeSurface(original);

    // Return the converted. If it's bad it'll be null, I guess.
    return formattedBMP;
}

void blitScene( SDL_Surface* screen, SDL_Surface* ground, SDL_Surface* wall, SDL_Surface* robot) {

    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;

    SDL_Rect groundDest;
    groundDest.x = 0;
    groundDest.y = 800;

    SDL_Rect robotDest;
    robotDest.x = 500;
    robotDest.y = groundDest.y - robot->h;

    SDL_SetColorKey( robot, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 255, 255, 255) );

    SDL_BlitSurface(wall, NULL, screen, &dest);
    SDL_BlitSurface(ground, NULL, screen, &groundDest);
    SDL_BlitSurface(robot, NULL, screen, &robotDest);

    SDL_Flip(screen);
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    SDL_Event event;
    SDL_Surface* surface = NULL;

    SDL_Surface* ground = NULL;
    SDL_Surface* wall = NULL;
    SDL_Surface* robot = NULL;
        

    SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO );

    surface = SDL_SetVideoMode(1280, 960, 24, SDL_HWSURFACE | SDL_DOUBLEBUF);

    ground = getSurface("textured_glass_beige.bmp");
    if( ground == NULL ) {
        // How do I messagebox?
        return -1;
    }

    wall = getSurface("green_wallpaper.bmp");
    if( wall == NULL ) {
        return -2;
    }

    robot = getSurface("blue_mech.bmp");
    if( robot == NULL ) {
        return -3;
    }

    blitScene(surface, ground, wall, robot);
        
    while( true ) {
        SDL_PollEvent(&event);        

        if( event.type == SDL_QUIT ) {
            break;
        }
    }

    if( ground != NULL ) {
        SDL_FreeSurface(robot);
    }

    if( wall != NULL ) {
        SDL_FreeSurface(wall);
    }

    if( ground != NULL ) {
        SDL_FreeSurface(ground);
    }

    SDL_FreeSurface(surface);

    SDL_Quit();
    
	return 0;
}