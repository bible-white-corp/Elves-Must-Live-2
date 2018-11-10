#include <err.h>
#include "rendering.h"


void load_blocks(struct game *game)
{
    SDL_Texture *grass_text = IMG_LoadTexture(game->renderer,
            GRASS_PATH);
    if (!grass_text)
        warnx("cannot convert grass_surface to SDL_Texture");

    SDL_Texture *void_text = IMG_LoadTexture(game->renderer,
            VOID_PATH);
    if (!grass_text)
        warnx("cannot convert void_surface to SDL_Texture");

    SDL_Texture *lava_text = IMG_LoadTexture(game->renderer,
            LAVA_PATH);
    if (!lava_text)
        warnx("cannot convert lava_surface to SDL_Texture");


    game->texture_lib[VOID] = void_text;
    game->texture_lib[GRASS] = grass_text;
    game->texture_lib[LAVA] = lava_text;

}

static void load_players_jump(struct game *game)
{
    SDL_Texture *prj_text = IMG_LoadTexture(game->renderer,
            PRJUMP_PATH);
    if (!prj_text)
        warnx("cannot convert player right jump to SDL_Texture");

    SDL_Texture *plj_text = IMG_LoadTexture(game->renderer,
            PLJUMP_PATH);
    if (!plj_text)
        warnx("cannot convert player left jump to SDL_Texture");

    SDL_Texture *pfj_text = IMG_LoadTexture(game->renderer,
            PFJUMP_PATH);
    if (!pfj_text)
        warnx("cannot convert player front jump to SDL_Texture");

    game->texture_lib[PRJ] = prj_text;
    game->texture_lib[PLJ] = plj_text;
    game->texture_lib[PFJ] = pfj_text;
}

void load_players(struct game *game)
{
    SDL_Texture *pr0_text = IMG_LoadTexture(game->renderer,
            PR0_PATH);
    if (!pr0_text)
        warnx("cannot convert player right 0 to SDL_Texture");

    SDL_Texture *pr1_text = IMG_LoadTexture(game->renderer,
            PR1_PATH);
    if (!pr1_text)
        warnx("cannot convert player right 1 to SDL_Texture");

    SDL_Texture *pr2_text = IMG_LoadTexture(game->renderer,
            PR2_PATH);
    if (!pr2_text)
        warnx("cannot convert player right 2 to SDL_Texture");

    SDL_Texture *pl0_text = IMG_LoadTexture(game->renderer,
            PL0_PATH);
    if (!pl0_text)
        warnx("cannot convert player left 0 to SDL_Texture");

    SDL_Texture *pl1_text = IMG_LoadTexture(game->renderer,
            PL1_PATH);
    if (!pl1_text)
        warnx("cannot convert player left 1 to SDL_Texture");

    SDL_Texture *pl2_text = IMG_LoadTexture(game->renderer,
            PL2_PATH);
    if (!pl2_text)
        warnx("cannot convert player left 2 to SDL_Texture");

    SDL_Texture *pf_text = IMG_LoadTexture(game->renderer,
            PF_PATH);
    if (!pf_text)
        warnx("cannot convert player front to SDL_Texture");


    game->texture_lib[PL0] = pl0_text;
    game->texture_lib[PL1] = pl1_text;
    game->texture_lib[PL2] = pl2_text;
    game->texture_lib[PR0] = pr0_text;
    game->texture_lib[PR1] = pr1_text;
    game->texture_lib[PR2] = pr2_text;
    game->texture_lib[PF] = pf_text;
    load_players_jump(game);
}
