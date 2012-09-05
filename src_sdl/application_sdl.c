
#include <stdlib.h>

#include <wisper/application/sdl.h>
#include <wisper/my.h>

#include <stdio.h>
#include <assert.h>

application_t new_application_sdl(const char *name, const char *version)
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
	
	SDL_WM_SetCaption(my_str_join(" - ",self->name,self->version,0), 
		"something");
	return self;
}

screen_t build_screen(int x, int y)
{
	assert(x > 0 && y > 0);
	
	screen_t screen = SDL_SetVideoMode(x,y,24,SDL_HWSURFACE);
	
	return screen;
}
