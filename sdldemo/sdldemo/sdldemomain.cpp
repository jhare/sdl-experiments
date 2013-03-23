#include "stdafx.h"
#include "sdldemomain.h"

using namespace SDLDemo;

SDLDemoMain::SDLDemoMain() {

}

SDLDemoMain::~SDLDemoMain() {

}

int SDLDemoMain::Initialize() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	this->__screen = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE | SDL_DOUBLEBUF); 

	if( this->__screen == NULL ) {
		return SDLDemo::E_SCREEN_NULL;
	}
	
	return 0;
}

int SDLDemoMain::Shutdown() {
	SDL_Quit();
	return 0;
}

void SDLDemoMain::Loop() {

}

void SDLDemoMain::Render() {

}

bool SDLDemoMain::Events() {

	SDL_Event event;
	
	if( SDL_PollEvent(&event) ) {
		if( event.type  == SDL_QUIT ) {
			return false;
		}
	}

	return true;
}