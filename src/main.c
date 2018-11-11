#include <stdlib.h>
#include <stdio.h>

#include "eml2.h"
#include "rendering.h"
#include "vector.h"
#include "parser.h"
#include "inputs.h"
#include "physics.h"
#include "menu.h"

void init_map(struct game *game, int lvl)
{
    char str[100] = { 0 };
    sprintf(str, "maps/lvl%d.eml", lvl);
    if (lvl == 0)
        map_parse(str, game->map, 1);
    else
        map_parse(str, game->map, 0);
    game->map->delims = NULL;
    compute_delims(game->map);
}

void init_game(struct game *game)
{
    game->is_playing = 1;
    game->lvl = 0;
    game->map = malloc(sizeof(struct map));
    init_map(game, game->lvl);
    game->timer = 0;
    game->timer_lava = 0;
}

void destroy_game(struct game *game)
{
    // Free stuff
    free(game->map->delims);
    map_delete(game->map);
    free(game->map);
}

void launch_game(struct game *game)
{
    short death = 0;
    init_game(game);
    while (game->is_playing)
    {
        // Get keyboard inputs
        struct inputs in =
        {
            0, 0, 0, 0, 0, 0
        };
        if (death == 0)
            in = get_inputs();

        // Call physics funcs
        int res = update(game, in);
        if (res > 0)
        {
            float save_y = game->map->players[0]->position.y;
            init_map(game, game->lvl);
            game->map->players[0]->position.y = save_y - 1;
            if (res == 1)
                game->map->players[0]->position.x = 48;
            if (res == 2)
                game->map->players[0]->position.x = 2;
        }
        if (in.cheat && game->map->players[0]->is_attacking)
        {
            init_map(game, ++game->lvl);
            game->map->players[0]->orientation = 0;
            game->map->players[0]->is_ground = 0;
            game->map->players[0]->has_jumped = 0;
            game->map->players[0]->is_attacking = 0;
        }
        if (res == -2)
        {
            render_victory(game);
            break;
        }
        if (res == -1)
        {
            if (death == 1)
            {
                render_defeat(game);
                break;
            }
            Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
            game->music = Mix_LoadMUS("ressources/mp3/death.mp3");
            Mix_PlayMusic(game->music, 1);
            death = 1;
            struct vec2 pos = game->map->players[0]->position;
            struct vec2 velo = {0, 0};
            init_map(game, 99);
            game->map->players[0]->position = pos;
            game->map->players[0]->velocity = velo;
            game->map->players[0]->orientation = 0;
            game->map->players[0]->is_ground = 0;
            game->map->players[0]->has_jumped = 0;
            move_jump(game->map->players[0]);
        }

        // Render new frame
        render_frame(game);
    }
    destroy_game(game);

}

void launch_main_menu(struct game *game)
{
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    game->music = Mix_LoadMUS("ressources/mp3/intro.mp3");
    Mix_PlayMusic(game->music, -1);
    while (1)
    {
        int res = main_menu(game);
        if (res == 1)
        {
            launch_game(game);
            Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
            game->music = Mix_LoadMUS("ressources/mp3/intro.mp3");
            Mix_PlayMusic(game->music, -1);
        }
        else if (res == -1)
        {
            break;
        }
    }
}



int main(void)
{
    struct game game;
    // Init SDL2 stuff
    game.texture_lib = calloc(60, sizeof(SDL_Texture*));
    init_sdl(&game);
    load_textures(&game);
    launch_main_menu(&game);
    destroy_sdl(&game);
    free(game.texture_lib);
}
