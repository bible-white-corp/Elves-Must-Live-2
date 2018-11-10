#pragma once

#define WIN_WIDTH 800
#define WIDTH 50
#define WIN_HEIGHT 640
#define HEIGHT 40
#define BLOCK_SIZE 16

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stddef.h>

#include "vector.h"

enum block
{
    VOID = 0,
    GRASS = 1,
    LAVA = 2,
    PL0 = 10,
    PL1 = 11,
    PL2 = 12,
    PR0 = 13,
    PR1 = 14,
    PR2 = 15,
    PF = 16,
    PLJ = 17,
    PRJ = 18,
    PFJ = 19,
    AL0 = 20,
    AL1 = 21,
    AR0 = 22,
    AR1 = 23
};

struct map
{
    struct character **players;
    size_t n_players;

    struct line *delims;
    size_t n_delims;

    enum block **grid; //grid[height][width] merci Louis
};

struct character
{
    short is_player; //further implementation will change this in enum
    struct map *map;

    short is_ground;

    short is_dead;

    struct vec2 size;

    struct vec2 position;
    struct vec2 velocity;
    struct vec2 acceleration;
};

struct game
{
    short is_playing;
    struct map *map;
    int lvl;
    int timer;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture **texture_lib;
};
