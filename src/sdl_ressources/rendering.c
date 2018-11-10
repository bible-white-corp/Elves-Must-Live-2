#include <SDL.h>
#include <SDL_image.h>
#include <err.h>
#include "rendering.h"

void init_sdl(struct game *game)
{
   if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
        errx("could not init SDL: %s", SDL_GetError());//get explicit error msg

   SDL_Window *win = SDL_CreateWindow(GAME_NAME,
           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
           WIN_WIDTH, WIN_HEIGHT, 0);

   if (!win)
   {
        warnx("could not init SDL window: %s", SDL_GetError());
        SDL_Quit();
        exit(2);
   }



}
