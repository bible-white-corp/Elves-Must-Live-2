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

static void render_QUIT(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 720;
    dstrect.y = 560;
    dstrect.w = 50;
    dstrect.h = 50;

    SDL_RenderCopy(game->renderer, game->texture_lib[DOOR], NULL, &dstrect);
}

static void render_QUITS(struct game *game)
{
    SDL_Rect dstrect;
    dstrect.x = 720;
    dstrect.y = 560;
    dstrect.w = 50;
    dstrect.h = 50;

    SDL_RenderCopy(game->renderer, game->texture_lib[DOORS], NULL, &dstrect);
}

int main_menu(struct game *game, char *menu)
{
    render_BG(game);
    render_EML(game);
    SDL_PumpEvents();
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    if (x > 300 && x < 500 && y < 326 && y > 276)
    {
        render_QUICKGAMES(game);
        if (SDL_BUTTON(SDL_BUTTON_LEFT))
            game->is_playing = 1;
    }
    else
        render_QUICKGAME(game);

    if (x > 300 && x < 500 && y > 356 && y < 406)
    {
        render_HISTORYS(game);
        if (SDL_BUTTON(SDL_BUTTON_LEFT))
            x=x;
    }
    else
        render_HISTORY(game);

    if (x > 300 && x < 500 && y > 516 && y < 566)
    {
        render_CREDITSS(game);
        if (SDL_BUTTON(SDL_BUTTON_LEFT))
            x=x;
    }
    else
        render_CREDITS(game);

    if (x > 720 && x < 770 && y > 560 && y < 610)
    {
        render_QUITS(game);
        if (SDL_BUTTON(SDL_BUTTON_LEFT))
            *menu = 0;
    }
    else
        render_QUIT(game);



    SDL_Delay(50);
    SDL_RenderPresent(game->renderer);
    return 1;
}
