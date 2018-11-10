#include <SDL2/SDL.h>
#include "inputs.h"
#include "physics.h"

struct inputs get_inputs(void)
{
    struct inputs in =
    {
        0, 0, 0, 0
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
    printf("inputs : %d %d %d %d\n", in.right, in.left, in.jump, in.quit);
    return in;
}

int update(struct game *game, struct inputs in)
{
    if (in.left)
        move_left(game->map->players[0]);
    if (in.right)
        move_right(game->map->players[0]);
    if (in.jump)
        move_jump(game->map->players[0]);
    if (in.quit)
    {
        printf("ABORT !!\n");
        game->is_playing = 0;
    }
    apply_gravity(game->map);
    int res = move_all(game->map);
    if (res == 1)
        game->lvl--;
    if (res == 2)
        game->lvl++;
    return res;
}
