#pragma once

#include "eml2.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 640
#define GAME_NAME "Elves Must Live 2"
#define GRASS_PATH "ressources/blocks/grass.png"
#define VOID_PATH "ressources/blocks/void.png"


void init_sdl(struct game *game);
void destroy_sdl(struct game *game);
void load_textures(struct game *game);
void render_frame(struct game *game);
