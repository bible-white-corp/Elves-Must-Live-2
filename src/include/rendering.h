#pragma once

#include "eml2.h"

#define GAME_NAME "Elves Must Live 2"
#define LAVA_PATH "ressources/blocks/lava.png"
#define GRASS_PATH "ressources/blocks/grass.png"
#define VOID_PATH "ressources/blocks/void.png"

#define PL0_PATH "ressources/Player/left0.png"
#define PL1_PATH "ressources/Player/left1.png"
#define PL2_PATH "ressources/Player/left2.png"
#define PLJUMP_PATH "ressources/Player/leftjump.png"

#define PR0_PATH "ressources/Player/right0.png"
#define PR1_PATH "ressources/Player/right1.png"
#define PR2_PATH "ressources/Player/right2.png"
#define PRJUMP_PATH "ressources/Player/rightjump.png"

#define PF_PATH "ressources/Player/front.png"
#define PFJUMP_PATH "ressources/Player/frontjump.png"

#define AR0_PATH "ressources/Player/attackingright0.png"
#define AR1_PATH "ressources/Player/attackingright1.png"
#define AL0_PATH "ressources/Player/attackingleft0.png"
#define AL1_PATH "ressources/Player/attackingleft1.png"

#define EL0_PATH "ressources/Ennemies/left0.png"
#define EL1_PATH "ressources/Ennemies/left1.png"
#define ER0_PATH "ressources/Ennemies/right0.png"
#define ER1_PATH "ressources/Ennemies/right1.png"
#define EF_PATH "ressources/Ennemies/front.png"
#define EFJ_PATH "ressources/Ennemies/frontjump.png"


#define TIMER_MAX 20
#define TIMER_MAX2 10

#define TIMER_MAX_ATTACK 30
#define TIMER_MAX_ATTACK2 15

//load.c
void load_blocks(struct game *game);
void load_players(struct game *game);

//rendering.c
void init_sdl(struct game *game);
void destroy_sdl(struct game *game);
void load_textures(struct game *game);
void render_frame(struct game *game);
