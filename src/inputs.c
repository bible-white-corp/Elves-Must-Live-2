#include <SDL2/SDL.h>
#include "inputs.h"
#include "physics.h"

struct inputs get_inputs(void)
{
    struct inputs in =
    {
        0, 0, 0, 0, 0
    };
    SDL_PumpEvents();
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_RIGHT])
        in.right = 1;
    if (state[SDL_SCANCODE_LEFT])
        in.left = 1;
    if (state[SDL_SCANCODE_SPACE])
        in.jump = 1;
    if (state[SDL_SCANCODE_ESCAPE])
        in.quit = 1;
    if (state[SDL_SCANCODE_RCTRL])
        in.attack = 1;
    return in;
}

short check_block(struct character *pnj, int delta)
{
    int x = pnj->position.x / 1;
    int y = pnj->position.y / 1;
    if (pnj->map->grid[y+1][x + delta] == GRASS)
        return 1;
    if (pnj->map->grid[y +2][x + delta] == GRASS)
        return 1;
    if (pnj->map->grid[y+3][x + delta] != GRASS)
        return 1;
    return 0;
}

void best_ia(struct game *game)
{
    for (size_t i = 1; i < game->map->n_players; i++)
{
        struct character *pnj = game->map->players[i];
        if (pnj->orientation == 1 && check_block(pnj, 2))
        {
            pnj->orientation = -1;
        }
        if (pnj->orientation == -1 && check_block(pnj, -1))
        {
            pnj->orientation = 1;
        }
        if (pnj->orientation == -1)
            move_left(pnj);
        else
            move_right(pnj);
    }
}

int update(struct game *game, struct inputs in)
{
    if (in.left)
        move_left(game->map->players[0]);
    if (in.right)
        move_right(game->map->players[0]);
    if (in.jump)
        move_jump(game->map->players[0]);
    if (in.attack && game->map->players[0]->is_attacking == 0)
        game->map->players[0]->is_attacking = 1;
    best_ia(game);
    if (in.quit)
    {
        printf("ABORT !!\n");
        game->is_playing = 0;
    }
    apply_gravity(game->map);
    int res = move_all(game->map);
    if (res == 1)
        return -2;
    for (size_t i = 0; i < 1; i++)
    {
        struct character *player = game->map->players[i];
        int dir = player->velocity.x > 0.01 ? 1 : player->velocity.x < -0.01 ? -1 : 0;
        if (dir == -1)
            player->orientation = -1;
        if (dir == 1)
            player->orientation = 1;
        printf("x %f\ny %f\n%d\n\n", player->velocity.x, player->velocity.y, player->orientation);
    }
    if (game->map->players[0]->position.x < 0)
    {
        game->lvl--;
        game->lvl = (game->lvl + 3) % 3;
        return 1;
    }
    if (game->map->players[0]->position.x > 49)
    {
        game->lvl++;
        game->lvl = (game->lvl + 3) % 3;
        return 2;
    }
    if (res == -1)
        return -1;
    return 0;
}
