#pragma once

#define WIN_WIDTH 800
#define WIDTH 50
#define WIN_HEIGHT 640
#define HEIGHT 40
#define BLOCK_SIZE 16

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stddef.h>

//#include "vector.h"

enum block
{
    VOID = 0,
    GRASS = 1
};

struct map
{
    struct character **players;
    size_t n_players;

    //struct vec2 *delims;
    size_t n_delims_duos; //n * 2 delims presents

    enum block **grid; //grid[height][width] merci Louis
};

struct character
{
    short is_player; //further implementation will change this in enum
    struct map *map;

    //struct vec2 size;

    //struct vec2 position;
    //struct vec2 velocity;
    //struct vec2 acceleration;
};

struct game
{
    short is_playing;
    struct map *map;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture **texture_lib;
};
