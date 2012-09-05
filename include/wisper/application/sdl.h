

#ifndef _WISPER_APPLICATION_SDL_
# define _WISPER_APPLICATION_SDL_

#include <SDL/SDL.h>

#include <wisper/application.h>

typedef SDL_Surface* screen_t;

application_t new_application_sdl(const char *, const char *);

screen_t build_screen(int, int);
 
#endif

