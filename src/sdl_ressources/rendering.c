#include <SDL.h>
#include <SDL_image.h>
#include <err.h>
#include "rendering.h"

void init_sdl(struct game *game)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
        errx(2,"could not init SDL: %s", SDL_GetError());//get explicit err msg

    //init window
    SDL_Window *win = SDL_CreateWindow(GAME_NAME,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WIN_WIDTH, WIN_HEIGHT, 0);

    if (!win)
    {
        warnx("could not init SDL window: %s", SDL_GetError());
        SDL_Quit();
        exit(3);
    }

    //init renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1,
            SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        warnx("could not init SDL renderer: %s", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(4);
    }

    game->renderer = renderer;
    game->window = win;
}

void destroy_sdl(struct game *game)
{
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}

void render_frame(struct game *game)
{
    
}
