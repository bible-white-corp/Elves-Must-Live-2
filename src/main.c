#include <stdlib.h>

#include "eml2.h"
#include "rendering.h"
#include "parser.h"

void init_game(struct game *game)
{
    game->is_playing = 1;
    game->map = malloc(sizeof(struct map));
    map_parse("src/map.eml", game->map);
    game->texture_lib = calloc(10, sizeof(SDL_Texture*));

    // Init SDL2 stuff
    init_sdl(game);
    load_textures(game);
}

void destroy_game(struct game *game)
{
    // Free stuff
    map_delete(game->map);
    destroy_sdl(game);
    free(game->map);
    free(game->texture_lib);
}

int main(void)
{

    struct game game;
    init_game(&game);

    while (game.is_playing)
    {
        // Get keyboard inputs
        //struct input in = get_input();

        // Call physics funcs
        //update(&game, in);

        // Render new frame
        render_frame(&game);
    }
    destroy_game(&game);
}
