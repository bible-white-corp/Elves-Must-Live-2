#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stddef.h>

#include "vector.h"

struct map
{
    struct player **players;
    size_t n_players;

    struct vec2 *delims;
    size_t n_delims_duos; //n * 2 delims presents

    char **grid; //grid[height][width] merci Louis
};

struct character
{
    short is_player; //further implementation will change this in enum
    struct map *map;

    struct vec2 size;

    struct vec2 position;
    struct vec2 velocity;
    struct vec2 acceleration;
};

struct game
{
    short is_playing;
    struct map *map;
    SDL_Window *window;
    SDL_Renderer *renderer;
};
