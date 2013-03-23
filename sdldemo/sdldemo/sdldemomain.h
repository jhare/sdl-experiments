#ifndef __SDLDEMO_CONTROLLER
#define __SDLDEMO_CONTROLLER

namespace SDLDemo {
	
	/**
	 *
	 *
	 */
	class SDLDemoMain {

	public:

		SDLDemoMain();
		  
		~SDLDemoMain();

		int Initialize();
		int Shutdown();

		void Loop();
		void Render();
		bool Events();


	private:

		SDL_Surface* __screen;

		bool __isRunning;

	};

}

#endif