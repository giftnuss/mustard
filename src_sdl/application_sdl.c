
#include <stdlib.h>

#include <wisper/application/sdl.h>

application_t new_application_sdl(char *name, char *version)
{
	application_t self = new_application(name,version);
	
	int init = SDL_Init(
		SDL_INIT_VIDEO |
		SDL_INIT_AUDIO |
		SDL_INIT_TIMER );
	if(-1 == init) {
		exit(-1);
	}
	
	atexit(SDL_Quit);
	return self;
}
