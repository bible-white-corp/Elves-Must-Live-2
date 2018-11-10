#pragma once

#include "eml2.h"

#define GAME_NAME "Elves Must Live 2"
#define LAVA_PATH "ressources/blocks/lava.png"
#define GRASS_PATH "ressources/blocks/grass.png"
#define VOID_PATH "ressources/blocks/void.png"

#define PL0_PATH "ressources/Player/left0.png"
#define PL1_PATH "ressources/Player/left1.png"
#define PL2_PATH "ressources/Player/left1.png"
#define PLJUMP_PATH "ressources/Player/leftjump.png"


#define PR0_PATH "ressources/Player/right0.png"
#define PR1_PATH "ressources/Player/right1.png"
#define PR2_PATH "ressources/Player/right2.png"
#define PRJUMP_PATH "ressources/Player/rightjump.png"

#define PF_PATH "ressources/Player/front.png"
#define PFJUMP_PATH "ressources/Player/frontjump.png"


#define TIMER_MAX 90

//load.c
void load_blocks(struct game *game);
void load_players(struct game *game);

//rendering.c
void init_sdl(struct game *game);
void destroy_sdl(struct game *game);
void load_textures(struct game *game);
void render_frame(struct game *game);
