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
    SDL_DestroyTexture(game->texture_lib[VOID]);
    SDL_DestroyTexture(game->texture_lib[GRASS]);
    SDL_DestroyTexture(game->texture_lib[LAVA]);

    SDL_DestroyTexture(game->texture_lib[PR0]);
    SDL_DestroyTexture(game->texture_lib[PR1]);
    SDL_DestroyTexture(game->texture_lib[PR2]);
    SDL_DestroyTexture(game->texture_lib[PL0]);
    SDL_DestroyTexture(game->texture_lib[PL1]);
    SDL_DestroyTexture(game->texture_lib[PL2]);
    SDL_DestroyTexture(game->texture_lib[PF]);
    SDL_DestroyTexture(game->texture_lib[PFJ]);
    SDL_DestroyTexture(game->texture_lib[PRJ]);
    SDL_DestroyTexture(game->texture_lib[PLJ]);


    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}

void load_textures(struct game *game)
{
    load_blocks(game);
    load_players(game);
}

static int get_timer(struct game *game)
{
    int res = game->timer;
    game->timer += 1;
    if (game->timer > TIMER_MAX)
        game->timer = 0;
    return res;
}

static SDL_Texture *select_player_sprite(struct game *game,
        struct character *player)
{
    int timer = get_timer(game);
    int index = timer / 45;
    int dir = player->velocity.x > 0 ? -1 : player->velocity.x == 0 ? 0 : 1;
    if (dir == 0)
    {
        if (player->velocity.y < 0.1 ||player->velocity.y > -0.1 )
            return game->texture_lib[PF];
        return game->texture_lib[PFJ];
    }
    if (dir == 1)
    {
        if (player->velocity.y >= 0.1 ||player->velocity.y <= -0.1)
            return game->texture_lib[PLJ];
        if (index == 0)
            return game->texture_lib[PL0];
        /*else if (index == 1)
            return game->texture_lib[PL1];*/
        return game->texture_lib[PL2];
    }
    if (player->velocity.y >= 0.1 ||player->velocity.y <= -0.1)
            return game->texture_lib[PRJ];
        if (index == 0)
            return game->texture_lib[PR0];
        /*else if (index == 1)
            return game->texture_lib[PR1];*/
        return game->texture_lib[PR2];

}
void render_players(struct game *game)
{
    for (size_t i = 0; i < game->map->n_players; i++)
    {
        SDL_Rect dstrect;
            dstrect.x = game->map->players[i]->position.x * BLOCK_SIZE;
            dstrect.y = game->map->players[i]->position.y * BLOCK_SIZE;
            dstrect.w = BLOCK_SIZE;
            dstrect.h = 2 * BLOCK_SIZE;

            struct character *player = game->map->players[i];
            SDL_Texture *text;
            if (!player->is_player)
                text = select_player_sprite(game, player);
            else
                text= NULL;

            SDL_RenderCopy(game->renderer, text, NULL, &dstrect);
    }
}

static void render_map(struct game *game)
{
    int imax = WIN_WIDTH / BLOCK_SIZE;
    int jmax = WIN_HEIGHT / BLOCK_SIZE;

    for (int j = 0; j < jmax; j++)
    {
        for (int i = 0; i < imax; i++)
        {
            SDL_Rect dstrect;

            dstrect.x = i * BLOCK_SIZE;
            dstrect.y = j * BLOCK_SIZE;
            dstrect.w = BLOCK_SIZE;
            dstrect.h = BLOCK_SIZE;

            SDL_RenderCopy(game->renderer,
                    game->texture_lib[game->map->grid[j][i]],
                    NULL,
                    &dstrect);
        }
    }

}
void render_frame(struct game *game)
{
    render_map(game);
    render_players(game);
    SDL_RenderPresent(game->renderer);
}
