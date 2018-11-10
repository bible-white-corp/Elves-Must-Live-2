#include "menu.h"

static void render_EML(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 240;
    dstrect.y = 100;
    dstrect.w = 320;
    dstrect.h = 76;

    SDL_RenderCopy(game->renderer, game->texture_lib[EML], NULL, &dstrect);
}

static void render_QUICKGAME(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 300;
    dstrect.y = 276;
    dstrect.w = 200;
    dstrect.h = 50;

    SDL_RenderCopy(game->renderer, game->texture_lib[QUICKGAME],
            NULL, &dstrect);
}

static void render_QUICKGAMES(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 300;
    dstrect.y = 276;
    dstrect.w = 200;
    dstrect.h = 50;

    SDL_RenderCopy(game->renderer, game->texture_lib[QUICKGAMES],
            NULL, &dstrect);
}

static void render_HISTORY(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 300;
    dstrect.y = 356;
    dstrect.w = 200;
    dstrect.h = 50;

    SDL_RenderCopy(game->renderer, game->texture_lib[HISTORY],
            NULL, &dstrect);
}

static void render_HISTORYS(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 300;
    dstrect.y = 356;
    dstrect.w = 200;
    dstrect.h = 50;

    SDL_RenderCopy(game->renderer, game->texture_lib[HISTORYS],
            NULL, &dstrect);
}

static void render_CREDITS(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 300;
    dstrect.y = 516;
    dstrect.w = 200;
    dstrect.h = 50;

    SDL_RenderCopy(game->renderer, game->texture_lib[CREDITS],
            NULL, &dstrect);
}

static void render_CREDITSS(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 300;
    dstrect.y = 516;
    dstrect.w = 200;
    dstrect.h = 50;

    SDL_RenderCopy(game->renderer, game->texture_lib[CREDITSS],
            NULL, &dstrect);
}

static void render_BG(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = WIN_WIDTH;
    dstrect.h = WIN_HEIGHT;

    SDL_RenderCopy(game->renderer, game->texture_lib[BG], NULL, &dstrect);
}


int main_menu(struct game *game)
{
    render_BG(game);
    SDL_RenderPresent(game->renderer);
    return 1;
}
