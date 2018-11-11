#pragma once

#include "eml2.h"

#define GAME_NAME "Elves Must Live 2"
#define LAVA1_PATH "ressources/blocks/lava2.png"
#define LAVA2_PATH "ressources/blocks/lava3.png"
#define LAVA3_PATH "ressources/blocks/lava4.png"
#define GRASS_PATH "ressources/blocks/grass.png"
#define VOID_PATH "ressources/blocks/void.png"
#define PRINCESS_PATH "ressources/blocks/princess.png"
#define BACK_PATH "ressources/Menus/back_game.png"

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

#define AR0_PATH "ressources/Player/attackright0.png"
#define AR1_PATH "ressources/Player/attackright1.png"
#define AL0_PATH "ressources/Player/attackleft0.png"
#define AL1_PATH "ressources/Player/attackleft1.png"

#define EL0_PATH "ressources/Ennemies/left0.png"
#define EL1_PATH "ressources/Ennemies/left1.png"
#define ER0_PATH "ressources/Ennemies/right0.png"
#define ER1_PATH "ressources/Ennemies/right1.png"
#define EF_PATH "ressources/Ennemies/front.png"
#define EFJ_PATH "ressources/Ennemies/frontJ.png"

#define DOOR_PATH "ressources/Menus/quit.png"
#define DOORS_PATH "ressources/Menus/quitS.png"
#define BG_PATH "ressources/Menus/background.png"
#define CREDITS_PATH "ressources/Menus/credits.png"
#define CREDITSS_PATH "ressources/Menus/creditsS.png"
#define EML_PATH "ressources/Menus/eml.png"
#define HISTORY_PATH "ressources/Menus/history.png"
#define HISTORYS_PATH "ressources/Menus/historyS.png"
#define QUICKGAME_PATH "ressources/Menus/quickgame.png"
#define QUICKGAMES_PATH "ressources/Menus/quickgameS.png"

#define TIMER_MAX 20
#define TIMER_MAX2 10

#define TIMER_MAX_ATTACK 30
#define TIMER_MAX_ATTACK2 15

#define TIMER_MAX_LAVA 60
#define TIMER_MAX_LAVA3 20


//load.c
void load_blocks(struct game *game);
void load_players(struct game *game);

//rendering.c
void init_sdl(struct game *game);
void destroy_sdl(struct game *game);
void load_textures(struct game *game);
void render_frame(struct game *game);
